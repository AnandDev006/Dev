# Usage
```bash
export CF_CONTEST=https://codeforces.com/contest/1330
node script.js
# will parse all the problems of the contest
# download their testcases
# create multiple directories A B C D E depending on the number of problems in contest
# each directory created will have 
#    in0.txt out0.txt 
#    in1.txt out1.txt and so on 
# which represent the testcases downloaded
```