# C++ Conversions: `char`, `int`, and `string`

## 1. `char` → `string` ✅

### Method 1 (Recommended)

``` cpp
char ch = 'A';
string s(1, ch);

cout << s;   // A
```

### Method 2

``` cpp
char ch = 'A';
string s = string(1, ch);
```

### ❌ This is invalid

``` cpp
char ch = 'A';

string s = (string)ch;   // Error
string s(ch);            // Error
```

------------------------------------------------------------------------

## 2. `int` → `string` ✅

Use `to_string()`.

``` cpp
int x = 123;

string s = to_string(x);

cout << s;    // "123"
```

### ❌ Don't do this

``` cpp
int x = 123;

string s = (string)x;   // Error
```

------------------------------------------------------------------------

## 3. `string` → `int`

``` cpp
string s = "456";

int x = stoi(s);

cout << x;    // 456
```

------------------------------------------------------------------------

## 4. `string` → `char`

If the string contains one character:

``` cpp
string s = "A";

char ch = s[0];
```

------------------------------------------------------------------------

## 5. `int` → `char`

``` cpp
int x = 65;

char ch = (char)x;

cout << ch;   // A
```

or

``` cpp
char ch = static_cast<char>(65);
```

------------------------------------------------------------------------

## 6. `char` → `int`

``` cpp
char ch = 'A';

int x = ch;

cout << x;    // 65
```

or

``` cpp
int x = static_cast<int>(ch);
```

------------------------------------------------------------------------

## Summary

  From       To         Method
  ---------- ---------- -----------------------------------------------
  `char`     `string`   `string(1, ch)`
  `int`      `string`   `to_string(x)`
  `string`   `int`      `stoi(s)`
  `char`     `int`      `static_cast<int>(ch)` or implicit conversion
  `int`      `char`     `static_cast<char>(x)`
  `string`   `char`     `s[0]`

## Why can't we do `(string)ch`?

`string` is a **class**, not a primitive type. C-style casts only work
when a valid conversion exists. The `std::string` class has constructors
like:

``` cpp
string(size_t count, char ch);
string(const char* str);
```

but **it does not have a constructor that takes a single `char` or a
single `int`**, so `(string)ch` and `(string)x` are invalid. That's why
you use `string(1, ch)` for a character and `to_string(x)` for an
integer.
