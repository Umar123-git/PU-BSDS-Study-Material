from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score
from sklearn.model_selection import train_test_split
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder
import pandas as pd
from pathlib import Path


# ------------------------------
# Random Forest Class
# ------------------------------
class RandomForestModel:
    def __init__(self, n_estimators=100):
        self.n_estimators = n_estimators
        self.model = RandomForestClassifier(
            n_estimators=self.n_estimators,
            random_state=42
        )

    def train(self, X_train, y_train):
        self.model.fit(X_train, y_train)

    def predict(self, X_test):
        return self.model.predict(X_test)

    def evaluate(self, y_test, y_pred):
        accuracy = accuracy_score(y_test, y_pred)
        precision = precision_score(y_test, y_pred)
        recall = recall_score(y_test, y_pred)
        return accuracy, precision, recall


# ------------------------------
# Load Dataset
# ------------------------------
script_dir = Path(__file__).resolve().parent
dataset_path = script_dir / "train.csv"

if not dataset_path.exists():
    dataset_path = script_dir / "train_u6lujuX_CVtuZ9i.csv"

df = pd.read_csv(dataset_path)

# Drop unnecessary column
df.drop("Loan_ID", axis=1, inplace=True)

# Convert target
df["Loan_Status"] = df["Loan_Status"].map({"Y": 1, "N": 0})

# Features and target
X = df.drop("Loan_Status", axis=1)
y = df["Loan_Status"]

# Identify column types
categorical_cols = X.select_dtypes(include=["object"]).columns
numerical_cols = X.select_dtypes(exclude=["object"]).columns

# Preprocessing
numeric_transformer = Pipeline(steps=[
    ("imputer", SimpleImputer(strategy="median"))
])

categorical_transformer = Pipeline(steps=[
    ("imputer", SimpleImputer(strategy="most_frequent")),
    ("onehot", OneHotEncoder(handle_unknown="ignore"))
])

preprocessor = ColumnTransformer(
    transformers=[
        ("num", numeric_transformer, numerical_cols),
        ("cat", categorical_transformer, categorical_cols)
    ]
)

# Transform data
X_processed = preprocessor.fit_transform(X)

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X_processed, y, test_size=0.2, random_state=42
)

# ------------------------------
# Experimentation
# ------------------------------
estimators = [10, 50, 100]
results = []

for n in estimators:
    model = RandomForestModel(n_estimators=n)
    model.train(X_train, y_train)

    y_pred = model.predict(X_test)
    accuracy, precision, recall = model.evaluate(y_test, y_pred)

    results.append([n, accuracy, precision, recall])

# Results table
results_df = pd.DataFrame(
    results,
    columns=["n_estimators", "Accuracy", "Precision", "Recall"]
)

print(results_df)