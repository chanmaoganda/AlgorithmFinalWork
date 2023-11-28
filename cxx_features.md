```cpp
class Lambda {
    using pointer_type = long (*) (int, int &);
public:
    constexpr static auto FUNC(int value1, int &value2) -> long {return value1 + value2;}

    constexpr operator pointer_type () const { return FUNC; }

    constexpr auto operator()(int value1, int &value2) const -> long {return value1 + value2;}

    constexpr explicit operator int () const {return 1;}
};


int main() {
    auto l = Lambda{};
    long(*fp)(int, int&) = l;
    int num = (int)l;
    std::cout << num << "\n";
    return 0;
}
```

* lambdas (C++11)

* struct (C++98)

* constexpr (C++11)

* operator overloading (C++98)

* const member functions (C++11)

* braced initialization (C++11)

* `auto` return type deduction

* "compiler magic"

* function parameters (C++98)

* pass-by-value (C++98)

* attributes on parameters (C++11)

* pass-by-reference (C++98)

* pass-by-value vs pass-by-reference (C++98)

* pre-increment vs post-increment

* trailing return types (C++11)

* class vs struct (C++98)

* private vs public (C++98)

* implicit conversions (C++98)

* function pointers (C++98)

* static member functions (C++98)

* using aliases (C++11)

* efficiency when chaining functions

* templates argument type deduction (C++98)

* alias templates (C++11)

* template instantiaions (C++98)

* `noexcept` (C++11)

* `noexcept` in the type system (C++17)

* variadic templates (C++11)

* variadic lambdas (C++14)

* fold experssions (C++17)

* function attributes (C++11)
  
  ```cpp
  [[no_discard]] int add (int num1, int num2) { return num1 + num2;}
  ```

* concepts (C++20)

* non-type template parameters (C++98)

* integer sequences (C++11)

* template parameter pattern matching (C++11)

* explicit lambda templates (C++17)

* tuples (C++11)

* unpacking of tuples (C++11)

* variadic `sizeof...()` operator (C++11)

* direct-initialization of members (C++11)

* `mutable` keyword (C++98)

* non-`const` member functions (C++98)

* reference members (C++98)

* member copies
