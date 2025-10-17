#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

class Matrix
{
private:
    int** data;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int numRows = 0, int numCols = 0) : rows(numRows), cols(numCols)
    {
        if (numRows > 0 && numCols > 0)
        {
            data = new int* [rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j)
                {
                    data[i][j] = 0; // Initialize all elements to 0
                }
            }
        }
        else
        {
            data = nullptr;
        }
    }

    // Destructor
    ~Matrix()
    {
        if (data)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

    // Copy Constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
    {
        if (rows > 0 && cols > 0)
        {
            data = new int* [rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        else
        {
            data = nullptr;
        }
    }

    // Overload the assignment operator
    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            // Deallocate existing memory
            if (data)
            {
                for (int i = 0; i < rows; ++i)
                {
                    delete[] data[i];
                }
                delete[] data;
            }

            // Copy new dimensions and allocate memory
            rows = other.rows;
            cols = other.cols;
            if (rows > 0 && cols > 0)
            {
                data = new int* [rows];
                for (int i = 0; i < rows; ++i)
                {
                    data[i] = new int[cols];
                    for (int j = 0; j < cols; ++j)
                    {
                        data[i][j] = other.data[i][j];
                    }
                }
            }
            else
            {
                data = nullptr;
            }
        }
        return *this;
    }

    // Getters for rows and columns
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Set a value at a specific position
    void setValue(int row, int col, int val)
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            data[row][col] = val;
        }
        else
        {
            cout << "Invalid matrix indices." << endl;
        }
    }

    // Get a value from a specific position
    int getValue(int row, int col) const
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            return data[row][col];
        }
        else
        {
            cout << "Invalid matrix indices. Returning 0." << endl;
            return 0;
        }
    }

    // Display the matrix
    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << setw(3) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Read matrix data from a file
    bool readFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return false;
        }

        vector<vector<int>> temp_data;
        string line;
        int current_row = 0;
        int current_cols = 0;

        while (getline(file, line))
        {
            vector<int> row_data;
            stringstream ss(line);
            int value;
            while (ss >> value)
            {
                row_data.push_back(value);
            }
            if (!row_data.empty())
            {
                if (current_cols == 0)
                {
                    current_cols = row_data.size();
                }
                else if (current_cols != row_data.size())
                {
                    cout << "Mismatched column count in file." << endl;
                    return false;
                }
                temp_data.push_back(row_data);
                current_row++;
            }
        }
        file.close();

        if (current_row > 0 && current_cols > 0)
        {
            // Deallocate existing memory if necessary
            if (data)
            {
                for (int i = 0; i < rows; ++i)
                {
                    delete[] data[i];
                }
                delete[] data;
            }

            rows = current_row;
            cols = current_cols;
            data = new int* [rows];
            for (int i = 0; i < rows; ++i)
            {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j)
                {
                    data[i][j] = temp_data[i][j];
                }
            }
            return true;
        }
        else
        {
            cout << "File is empty or invalid." << endl;
            return false;
        }
    }
};