## **PayrollPro: Advanced Payroll Processing System** <br>

### **Project Overview:**

> <p> PayrollPro is a sophisticated C++ application designed to efficiently process complex payroll data from various departments within an organization. This project demonstrates advanced file I/O operations, string manipulation, data parsing, and mathematical calculations to handle diverse payroll scenarios. </p>

### **Key Features:**

>  1. *Multi-Department Support:* Processes payroll data for multiple departments simultaneously.
>  2. *Flexible Time Format Parsing:* Handles various time input formats (e.g., "8 hours 20 minutes", "7hrs 10min", "9 hours"). 
>  3. *Multiple Pay Grade Calculations:* Implements distinct calculation logic for different pay grades (F1, F2, F3, F4).
>  4. *Commission-Based Salary Processing:* Calculates salaries for commission-based employees (F3 grade).
>  5. *Overtime and Weekend Pay:* Accounts for overtime hours and special weekend rates for F4 grade employees.
>  6. *Robust Error Handling:* Ensures stability when processing inconsistent or unexpected input data.

## **Code Brainstorming:**

### **Memory Safety:**

>  1. Prefer stack allocation over heap allocation when possible.
>  2. Use std::array for fixed-size arrays instead of C-style arrays.
>  3. Employ std::vector for dynamic arrays.

### **Modern Language Features:**

>  1. Use auto for type inference where appropriate.
>  2. Employ range-based for loops.
>  3. Utilize structured bindings for multiple return values.

### **Functional Programming Concepts:**

>  1. Use lambda expressions for short, local functions.
>  2. Employ std::function for storing callable objects.
>  3. Utilize higher-order functions from 'algorithm' library.
