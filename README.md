[![Build Status](https://travis-ci.org/limingjie/all_to_istream.svg?branch=master)](https://travis-ci.org/limingjie/all_to_istream)

#All to istream
This is a dummy demo on how to process standard input, file or string as
istream.

##Why istream
It is common to interpret string, file or standard input (especially redirected)
character by character. To process them in a single function is very convenient,
which saves programmer some effort and provides a more user friendly interface.

Input stream can interpret input from sequences of characters. Useful functions
are provided or inherited from `ios` or `ios_base`.

[std::istream reference](http://www.cplusplus.com/reference/istream/istream/?kw=istream)

##How to convert different inputs to istream

- Standard input stream

  `std::cin` is defined as `istream`

  ```c++
  extern istream cin;
  ```

- `std::fstream` and `std::stringstream`

  Both `fstream` and `stringstream` are inherited from `iostream`, which inherited from `istream`.

  ```
  ios_base <--- ios <--- istream <--- iostream <--- fstream
                                               <--- stringstream
  ```

- `std::string`

  `string` can be converted to `stringstream`.

  ```c++
  explicit stringstream (const string& str,
                         ios_base::openmode which = ios_base::in | ios_base::out);
  ```

##Usage

```bash
$ ./all_to_istream.exe -u
Usage: all_to_istream
   or: all_to_istream FILE
   or: all_to_istream -s STRING
   or: all_to_istream -h
Process standard input, file or string as istream, to simplify support to different inputs.
```
