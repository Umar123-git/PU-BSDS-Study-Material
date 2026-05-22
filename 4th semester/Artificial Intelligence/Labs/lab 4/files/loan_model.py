import pandas as pd
from pathlib import Path
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score
from sklearn.model_selection import train_test_split

# Load Data 
BASE_DIR = Path(__file__).resolve().parent
train = pd.read_csv(BASE_DIR / 'train_u6lujuX_CVtuZ9i.csv')
test  = pd.read_csv(BASE_DIR / 'test_Y3wMUE5_7gLdaTN.csv')

# Preprocessing
def preprocess(df):
    df = df.copy()

    for col in df.columns:
        if df[col].dtype == "object" or str(df[col].dtype) == "string":
            df[col] = df[col].fillna(df[col].mode()[0])
        elif pd.api.types.is_numeric_dtype(df[col]):
            df[col] = df[col].fillna(df[col].mean())
    
    for col in df.select_dtypes(include="object").columns:
        df[col] = df[col].astype("category").cat.codes
    return df

loan_ids = test["Loan_ID"]
train = preprocess(train)
test  = preprocess(test)

features = [c for c in train.columns if c not in ["Loan_ID", "Loan_Status"]]
X = train[features]
y = train["Loan_Status"]
X_test_final = test[features]

X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)


# Task 1: Decision Tree Class
class DecisionTreeModel:
    def __init__(self, max_depth=5):
        self.max_depth = max_depth
        self.model = DecisionTreeClassifier(max_depth=self.max_depth, random_state=42)

    def train(self, X_train, y_train):
        self.model.fit(X_train, y_train)

    def predict(self, X_test):
        return self.model.predict(X_test)

    def evaluate(self, y_test, y_pred):
        accuracy  = accuracy_score(y_test, y_pred)
        precision = precision_score(y_test, y_pred)
        recall    = recall_score(y_test, y_pred)
        return accuracy, precision, recall


# Task 2: Random Forest Class
class RandomForestModel:
    def __init__(self, n_estimators=100):
        self.n_estimators = n_estimators
        self.model = RandomForestClassifier(n_estimators=self.n_estimators, random_state=42)

    def train(self, X_train, y_train):
        self.model.fit(X_train, y_train)

    def predict(self, X_test):
        return self.model.predict(X_test)

    def evaluate(self, y_test, y_pred):
        accuracy  = accuracy_score(y_test, y_pred)
        precision = precision_score(y_test, y_pred)
        recall    = recall_score(y_test, y_pred)
        return accuracy, precision, recall


# Print Task 01:
print("\n===== Task 01: Decision Tree =====")
print(f"{'Depth':<10} {'Accuracy':<12} {'Precision':<12} {'Recall'}")
print("-" * 46)

dt_results = []
best_dt_model = None
best_dt_acc = 0

for depth in [2, 5, None]:
    dt = DecisionTreeModel(max_depth=depth)
    dt.train(X_train, y_train)
    preds = dt.predict(X_val)
    acc, prec, rec = dt.evaluate(y_val, preds)
    dt_results.append((depth, acc, prec, rec))
    print(f"{str(depth):<10} {acc:<12.4f} {prec:<12.4f} {rec:.4f}")
    if acc > best_dt_acc:
        best_dt_acc = acc
        best_dt_model = dt


# Print Run Task 02: 
print("\n===== Task 02: Random Forest =====")
print(f"{'n_estimators':<15} {'Accuracy':<12} {'Precision':<12} {'Recall'}")
print("-" * 51)

rf_results = []
best_rf_model = None
best_rf_acc = 0

for n in [10, 50, 100]:
    rf = RandomForestModel(n_estimators=n)
    rf.train(X_train, y_train)
    preds = rf.predict(X_val)
    acc, prec, rec = rf.evaluate(y_val, preds)
    rf_results.append((n, acc, prec, rec))
    print(f"{n:<15} {acc:<12.4f} {prec:<12.4f} {rec:.4f}")
    if acc > best_rf_acc:
        best_rf_acc = acc
        best_rf_model = rf


# Submission File
final_preds = best_rf_model.predict(X_test_final)

label_map = {v: k for k, v in {"N": 0, "Y": 1}.items()}

unique_vals = sorted(y.unique())
decode = {unique_vals[0]: "N", unique_vals[1]: "Y"} if len(unique_vals) == 2 else {}

submission = pd.DataFrame({
    "Loan_ID": loan_ids,
    "Loan_Status": [decode.get(p, p) for p in final_preds]
})
submission.to_csv(BASE_DIR / 'submission.csv', index=False)
print("\nSubmission saved.")
print(submission.head())


import json
results = {"dt": dt_results, "rf": rf_results}
with open(BASE_DIR / "results.json", "w") as f:
    json.dump(results, f)
