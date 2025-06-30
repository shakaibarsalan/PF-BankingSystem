# Simple Banking System

This project is a C++ console application designed as a basic banking management system. It allows users to create and manage bank accounts, perform transactions, update information, and handle account security, all through a text-based interface. The system uses a plain text file (`Bank Database.txt`) for persistent data storage.

## Features

- **Account Creation**: Open a new account by providing personal details and setting a PIN.
- **User Authentication**: Secure login using account number and a 4-digit PIN.
- **Cash Withdraw/Deposit**: Deposit or withdraw cash from your account.
- **Funds Transfer**: Send money to another account within the bank.
- **PIN Management**: Change or reset your PIN securely.
- **Account Information**: View your account details and balance.
- **Account Deletion/Blocking**: Delete your account or have it blocked after multiple failed login attempts.
- **Admin Functions**: Update, block, or re-assign serial numbers for accounts (handled internally).

## How It Works

### Data Storage

- All account information is stored in a file named `Bank Database.txt`.
- Each record contains:
  - Serial Number
  - Account Number
  - First Name
  - Surname
  - Balance
  - Phone Number
  - PIN Code
  - Status (Active/Blocked)

### Main Functionalities

- **Login**: Enter your account number and PIN to access services.
- **Forgot PIN**: Reset your PIN if forgotten.
- **Account Operations**: Once authenticated, you can:
  - Withdraw cash
  - Deposit money
  - Transfer funds
  - Change PIN
  - View account info
  - Delete account

- **Account Blocking**: After 4 incorrect PIN attempts, the account is automatically blocked for security.

- **New Account**: Enter your name, phone number, and set a PIN. Optionally, make an initial deposit.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, MSVC)
- Console/terminal environment

### Compilation

```bash
g++ main.cpp -o Bank
```

### Running the Application

```bash
./Bank
```

### Usage

1. **Start the program**: Choose between logging in as an existing user, opening a new account, or exiting.
2. **Follow on-screen prompts**: Input required information as prompted.
3. **For existing users**: Enter your account number and PIN. If you forget your PIN, type `FORGOT` to reset it.
4. **For new users**: Provide your name, phone number (10 digits), and set a 4-digit PIN.

## File Structure

- `main.cpp` – Main source code containing all logic and functions.
- `Bank Database.txt` – Data file for storing account information (created automatically if not present).

## Important Notes

- **Data Safety**: All data is stored in plain text. For real-world use, consider encrypting sensitive data.
- **Error Handling**: The program includes basic error checks but is intended for educational/demo purposes.
- **Account Numbers**: New accounts are assigned a unique 6-digit number starting from `100049`.

## Example Account Record

```
1   100049  John    Doe     5000    3001234567  1234    A
```

## Authors

- Developed as a Programming Fundamentals (PF) project.

## License

This project is for educational purposes and demonstration only.
