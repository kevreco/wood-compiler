# wood
Recreational programming language compiler

Wood compiler will generate human-friendly to C files.
My goal is to have a better C, I was pretty frustrated to not have real templates.

Since simplicity is always the key I'll keep it as sober and as straightforward as possible.
Every single feature should be justified.

## Stage 0.0

The code smample should be compilable.
```
zero :: () -> int
{
   return 0;
}

main :: () -> int
{
    return zero();
}
```
### TODO

- Create cpp project for this compiler.
- Create tokenizer.
- Handle errors.
- Create lexer and AST.
- Create C generator.
- Combine everything.
