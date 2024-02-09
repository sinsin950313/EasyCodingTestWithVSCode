## Easy Coding Test with VSCode

### Keyword : Stream(fstream, sstream), 빌드 자동화(CMake, bat)

![300192303-da22c38d-a804-47cf-8c23-a903cae4f983.PNG](https://postfiles.pstatic.net/MjAyNDAyMDlfMjQy/MDAxNzA3NDczODQ0MzU3.S0j0h6qhpy5pRFPVt8sSqwFuR8zxs8mIfBGxKC0NXrEg.Jdjpt5eDk4WBkdNEXWI9GuiuyBk_64WpfgFR_TaD_T4g.PNG.sinsin63/300192303-da22c38d-a804-47cf-8c23-a903cae4f983.png?type=w580)

### 개요 : VSCode에서 쉽게 Coding Test 연습하기

백준이나 HackerRank의 경우 std::cin으로 예제를 입력받는데 Test를 위해 Build이후 직접 값을 넣어주기 번거로워서 자동화시키는 bat파일입니다.

### 기술 스택

- Cpp
- cmake
- bat

### 주요 기능

- bat
- CMake
- sstream
- fstream

# 사용법

## Help

![](/images/300191910-c6555b00-8d19-42c3-bfeb-5f9df246a572.PNG)

cmd에서 폴더에 위치한 후
```
main -h
```
를 누르면 도움말이 보입니다

## New Coding Test

![](/images/300192055-fb9d4fe1-689a-42d4-b178-7660e9a6ba56.PNG)

```
main -n { New Solution Name }
```
새로운 Test를 풀기위해 자동으로 cpp파일과 Sample을 저장하는 ini파일을 생성합니다

## Build

![](/images/300192169-39a97878-829f-42a5-a98d-1d6009da1093.PNG)

```
main -b { Solution Name }
```
확장자명 없이 cpp파일을 입력하면 자동으로 Build 합니다.

## Run

![](/images/300192303-da22c38d-a804-47cf-8c23-a903cae4f983.PNG)

```cpp
main -r { Solution Name }
```
ini파일이 미리 작성되어 있어야 합니다.

# ini File

![](/images/300192609-96ea59b0-1992-42b2-aeb4-8fcfaa7b9627.PNG)

Test를 수행할 Sample들을 저장하는 파일입니다.

ini를 확장자로 사용하고, cpp와 이름이 동일해야합니다.

"-Arg-"로 시작하여 그 아래로 Argument를 작성합니다.
<br>
"-Ans-" 이후 답을 작성합니다

Run을 통해 다수의 예제를 수행하고싶다면 Answer 아래에 다시 -Arg-부터 반복적으로 작성하면 됩니다.
<br>
자세한 예제는 Sample Directory를 확인하면 됩니다.

### 세부사항

[Easy Coding Test with VSCode](https://www.notion.so/Easy-Coding-Test-with-VSCode-d41b5be860ba49be9d67f875a1d57544?pvs=21)
