# Racket Cheatsheet

## Basic Syntax

- `;` for comments
- `#lang racket` defines the language
- `(define x 10)` defines a variable
- `(define (square n) (* n n))` defines a function
- `(display "Hello")` prints text
- `(newline)` prints a newline

---

## Data Types

- **Numbers**: `1`, `3.14`, `-2`
- **Strings**: `"hello"`
- **Booleans**: `#t` (true), `#f` (false)
- **Symbols**: `'x`, `'foo`
- **Lists**: `'(1 2 3)`
- **Vectors**: `#(1 2 3)`

---

## Conditionals

- `(if condition then-expr else-expr)`
- `(cond [(= x 0) "zero"] [(< x 0) "negative"] [else "positive"])`

---

## Loops and Recursion

- Recursion:
  - `(define (countdown n) (when (> n 0) (displayln n) (countdown (- n 1))))`
- `for` loop:
  - `(for ([i (in-range 5)]) (displayln i))` prints 0 to 4
  - `(for/list ([i '(1 2 3)]) (* i i))` returns `' (1 4 9)`

---

## Math Functions

- `(+ a b)`
- `(- a b)`
- `(* a b)`
- `(/ a b)`
- `(expt 2 3)` → 8
- `(sqrt 9)`
- `(modulo 5 2)`

---

## List Operations

- `(define lst '(1 2 3))`
- `(first lst)` → `1`
- `(rest lst)` → `'(2 3)`
- `(cons 0 lst)` → `'(0 1 2 3)`
- `(append lst '(4))` → `'(1 2 3 4)`
- `(length lst)`
- `(map square lst)`
- `(filter odd? lst)`
- `(foldl + 0 lst)`

---

## Functions

- `(define (add a b) (+ a b))`
- `(lambda (x) (* x x))` defines an anonymous function
- `((lambda (x) (* x x)) 5)` → `25`

---

## Useful Libraries

- `(require racket/list)`
- `(require racket/function)`
- `(require racket/match)`

---

## Boolean Logic

- `(and #t #t)` → `#t`
- `(or #f #t)` → `#t`
- `(not #t)` → `#f`
- `(equal? x y)` compares values

---

## Tips

- Racket uses **prefix notation**: `(+ 1 2)` instead of `1 + 2`
- Everything is an **expression**
- Avoid `set!` if you're writing in a functional style

