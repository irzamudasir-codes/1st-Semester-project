First Semester Project – C Programming
🎓 Examination Management System (C Language – CLI Based)

Welcome to my First Semester Project — a fully functional Student Examination Management System built in C language using file handling and structured programming.

Although it is a CLI (Command Line Interface) application, I focused heavily on making it clean, colorful, user-friendly, and structured, so the user experience still feels organized and professional.

🌟 Project Overview

This system is designed to simulate how examination management works in a real educational institution.

It supports two user roles:

👩‍🏫 Teacher

👨‍🎓 Student

Each role has its own secure login and dedicated features.

🔐 Secure Role-Based Access:

When the program starts, the user selects their role:

1) Teacher
2) Student

Each role has:

Separate password authentication

Separate menu interface

Separate functionalities

This ensures a clear separation between administrative and student-level operations.

👩‍🏫 Teacher Portal Features


After login, the teacher gets access to a complete management panel:

✅ Student Management


  ✔ Add new students (with duplicate ID checking)

✔  Update student name or marks

  ✔ Delete students

   ✔ View all registered students

🗓 Timetable Management

 ✔  Create exam timetable

 ✔  Assign subjects

 ✔  Assign invigilators

✔   Automatically generate exam dates

✔   Display timetable in formatted table view

📄 Admit Card Generation

✔   Generate admit card using student ID

 ✔  Automatically assigns exam room

 ✔  Displays timetable along with student details

📊 Result Management

 ✔ Enter subject-wise marks

 ✔  Automatically calculate:

  ✔ Total Marks

 ✔  GPA (4.0 scale)

 ✔  Grade (A–F)

 ✔  Store results in file

 ✔  Update results dynamically

 ✔  Display formatted result card with remarks

👨‍🎓 Student Portal Features:

The student interface is intentionally simple and clean.

After login, students can:

1)View Admit Card

2)View Result

3)Exit system

The goal was to keep it minimal and user-focused.

📁 File Handling System:

This project uses file handling to store and retrieve data:

✔ student_data.txt → Stores student IDs and names

✔ timetable.txt → Stores exam schedule

✔ result.txt → Stores total marks, GPA and grade

Data persists even after closing the program.


🧠 Technical Concepts Used:

1)This project demonstrates strong fundamentals of:

2)Structures (struct Student, struct timetable)

3)Arrays of structures

4)File handling (fopen, fprintf, fscanf)

5)Input validation

6)Conditional logic

7)Looping

8)Modular programming (multiple functions)

9)GPA calculation logic

10)Dynamic result updating

💡 Special Highlights:

✔ Duplicate ID prevention
✔ Automatic GPA calculation
✔ Grade and performance remarks system
✔ Color-coded CLI interface using ANSI escape codes
✔ Input validation with error handling
✔ Clean tabular output formatting

Even though it is CLI-based, the colored UI makes the experience much more interactive and readable.

🎯 Why I Built This->

As a first semester project, my goal was to:

1)Apply C programming concepts in a real-world scenario

2)Understand file handling practically

3)Practice modular design

4)Simulate an actual academic management system

This project helped me understand how backend systems work in educational software.

