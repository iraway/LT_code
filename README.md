# About
Luby transform codes (LT codes) are the first class of practical fountain codes that are near-optimal erasure correcting codes. They were invented by Michael Luby in 1998 and published in 2002.
# Requirements
| Resource | Version |
| ------ | ------ |
| gcc | gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 |
| cmake | 3.16.3 |

# Building and execution
```sh
$ cd LT_code
$ cmake --build . --target all
$ ./LT_code [file_in] [file_out]
```
