# Origin

https://github.com/MadGeorge/edu-console-application

# How to run

- Each task stored in separate folder
- C++ 11 is reuired

## Xcode

- Open ConsoleApplication.xcodeproj
- Select a scheme in the scheme dropdown   
- Press CMD+R

## Bash/Zsh

```bash
# run task D1.1
> g++ -std=c++11 D1.1/main.cpp && ./a.out

# run task D2.2
> g++ -std=c++11 D2.2/main.cpp && ./a.out

# run task D2.3 Part 1 
> g++ -std=c++11 D2.3/main.cpp && ./a.out login

# run task D2.3 Part 2 
> g++ -std=c++11 D2.3/main.cpp && ./a.out signup
> g++ -std=c++11 D2.3/main.cpp && ./a.out signin

# run task D2.4 
> g++ -std=c++11 -c D2.4/*.cpp && g++ *.o && ./a.out 7
```
