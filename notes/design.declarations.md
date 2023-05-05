# Various examples of declarations and definitions.

## Common

```c
s : struct { x: int; y: int}            // definition of struct
t : tuple {int; int;}                   // definition of tuple
e : enum { x; y; }                      // definition of enum
f : func () { }                         // definition of function taking nothing returning nothing
f : func (int) -> int { }               // definition of function taking int returning int
f : func ({int;int}) -> {int;int} { }   // definition of function taking tuple returning tuple

iv : int = 0;                // integer variable

sv : s = s.{ x = 0; y = 0 }; // variable of structure "s"
fv : (int) -> int  = &f;     // variable containing addres of function
tv : {int; int} = {0, 0};    // tuple variable
iv : int = void;             // uninitialize variable with explicit void
```

Every declaration starting with "struct", tuple, enum or func is a definition.
Any other are standard variable declaration where "identifier : type = value"


## Lambda - @Maybe
```c
lambda1 : x => x * x          // lambda with one parameter
lambda2 : (x, y) => x * x     // lambda with two parameters
lambda3 : {x; y} => x * y     // lambda with one tuple as parameter
```
Those lambda notations are just syncatic sugar for:
```c
lambda1 : func (x) -> typeof(x * x) { return x * x }
lambda2 : func (x, y) -> typeof(x * x) { return x * x }
lambda2 : func ({x; y}) -> typeof(x * y) { return x * y }
```

## Const - @Maybe
```c
c : const = 10;      // (1)?
const c := 10;       // (2)?
const {              // (3}?
    c3 := 10;
    c4 := 10;
}
```

It's not clear yet how to define const data.
Example (1) above is pretty verbose.
I like example (2) and (3) because we could see `const` as a global struct were we keep adding things.
It will make it very easy to reason about.

We might just need `identifier := value;`

## Var - @Maybe
```c
vv : var = 0;        // variable inferred from the equal value
``` 