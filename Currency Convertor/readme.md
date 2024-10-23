# Advanced Currency Converter in C++

This is an advanced currency converter program written in C++ that allows users to convert between various currencies like INR, USD, EUR, JPY, and GBP. The program provides a user-friendly interface where users can select the currency they have and the currency they want to convert to.

## Features

- Convert between multiple currencies:
  - INR (Indian Rupee)
  - USD (US Dollar)
  - EUR (Euro)
  - JPY (Japanese Yen)
  - GBP (British Pound)
- User-friendly interface with clear options for input.
- Input validation for currency selection.
- Recursive option to perform multiple conversions in one session.

## Conversion Rates

The conversion rates used in this program are predefined for simplicity and may not reflect real-time data. The table below shows the approximate rates relative to INR:

| From / To | INR  | USD   | EUR   | JPY   | GBP   |
|-----------|------|-------|-------|-------|-------|
| **INR**   | 1    | 0.012 | 0.011 | 1.61  | 0.0097|
| **USD**   | 83.0 | 1     | 0.92  | 134.6 | 0.79  |
| **EUR**   | 90.5 | 1.08  | 1     | 146.9 | 0.86  |
| **JPY**   | 0.62 | 0.0074| 0.0068| 1     | 0.0058|
| **GBP**   | 103.1| 1.27  | 1.16  | 170.2 | 1     |


## Example

Available currencies:
1. INR (Indian Rupee)
2. USD (US Dollar)
3. EUR (Euro)
4. JPY (Japanese Yen)
5. GBP (British Pound)

Select the currency you have (1-5): 2
Select the currency you want to convert to (1-5): 3
Enter the amount you want to convert: 100
Your amount 100 USD is 92 EUR.
Do you want to convert another currency? (1 for Yes, 2 for No): 1
