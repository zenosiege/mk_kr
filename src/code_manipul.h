//сверяет последовательность цифр заданной с той, что была введена пользователем
int codeVerify(const char trueCode[], char codeToBeChecked[], int codeSize) {
    int passValue = 1;

    for (int i = 0; i < codeSize; i++) {
        if (trueCode[i] != codeToBeChecked[i]) {
            passValue = 0;
        }
    }

    return passValue;

}