# Encode and Decode Strings

## Problem Description

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

## Linear Encoding and Decoding

### Approach (Encoding)

1. Initialize an encoded string with a delimiter `"-"`.
2. For each string in the input list:
   - Prepend the string to the encoded string.
   - Append the length of the string followed by a colon `":"` to mark the string's length.
3. The resulting encoded string contains all strings concatenated in order, with their lengths encoded as metadata at the end.

### Approach (Decoding)

1. Start at the end of the encoded string and locate the delimiter `"-"`, which separates the strings from their metadata.
2. Use two pointers beginning at delimiter `"-"` index:
   - One pointer (`i`) to traverse the encoded string backward to retrieve individual strings.
   - Another pointer (`n`) to traverse metadata forward to retrieve string lengths.
3. For each length:
   - Extract the corresponding string by moving the `i` pointer backward for the length value.
   - Append the string to the decoded list.
4. Continue until all lengths are processed and the entire input is decoded.

### Complexity (Encoding)

- **Time Complexity**: `O(m)`  
  - Where `m` is the total number of characters across all strings in the input list.
  - Each string is processed once and appended to the encoded string.

- **Space Complexity**: `O(m)`  
  - The encoded string grows in size proportional to the total number of characters in the input list.

### Complexity (Decoding)

- **Time Complexity**: `O(m)`  
  - The algorithm traverses the length metadata and processes each character in the encoded string once.

- **Space Complexity**: `O(m)`  
  - The decoded list stores all the original strings, requiring space proportional to the total number of characters.