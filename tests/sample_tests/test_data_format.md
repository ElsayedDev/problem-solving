# Test Data Format

Test data files use a simple format with input and expected output separated by "---".

## Format

```
<input_data>
---
<expected_output>
```

## Example

```
5
1 2 3 4 5
---
1 2 3 4 5
```

This represents:
- Input: First line is `5`, second line is `1 2 3 4 5`
- Expected output: `1 2 3 4 5`
