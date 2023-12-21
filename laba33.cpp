#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int choose = 0, idz = 0;

    while (choose != -1) {
        cout << "\n\n\n�� ������ �������, �������� ��, ������� ������ ���������: \n"
            "1.���������, ������� ��������� ���������� ����������, ��������� ������������ ������������� ������� ������� N (6,8,10) ���������� ������� �� 1 ��  N*N �������� ������.\n"
            "2.���������, ������� �������� ����� �������, �� ������� �. 1, ����������� �� ����� � ������������ �� �������.\n"
            "3.���������, ������� ��������� ���������� ����������, ��������� ��������(Insert sort).\n"
            "4.���������, ������� ���������, �����������, �������� ��� ����� ��� �������� ������� �� ��������� ������������� �����.\n"
            "5.���.\n\n\n";

        cout << "�������: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 5 and choose != 0)
            cout << "������ �������� ������ ��� \n";

        else
            switch (choose) {
          

            case 1: {
                int N;
                cout << "�������� ������ �������(6,8,10): ";
                cin >> N;

                int** arr = new int* [N];
                for (int i = 0; i < N; i++) {
                    arr[i] = new int[N];
                    for (int j = 0; j < N; j++) {
                        arr[i][j] = 0;
                    }
                }

                srand(time(NULL)); 

                for (int i = 0; i < N; i++) {
                    arr[i][0] = rand() % (N * N) + 1;
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr[i][j] << " ";
                    cout << "\n";
                }
                int dir = 0; //0 - ������ 1 - �����
                int i = N - 1;
                int j = 0;
                for (int step = N - 1; step > 0; step--) {
                    if (dir == 0) {
                        for (int st = 0; st < step; st++) {
                            j += 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        for (int st = 0; st < step; st++) {
                            i -= 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        dir = 1;
                    }
                    else{
                        
                        for (int st = 0; st < step; st++) {
                            j -= 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        for (int st = 0; st < step; st++) {
                            i += 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        dir = 0;
                    }
                    cout << "\n";
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++)
                            cout << arr[i][j] << " ";
                        cout << "\n";
                    }
                    cout << "\n";
                }
                
               
                arr = new int* [N];
                for (int i = 0; i < N; i++) {
                    arr[i] = new int[N];
                    for (int j = 0; j < N; j++) {
                        arr[i][j] = 0;
                    }
                }

                srand(time(NULL)); 

                for (int i = 0; i < N; i++) {
                    arr[i][0] = rand() % (N * N) + 1;
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr[i][j] << " ";
                    cout << "\n";
                }
                dir = 0; //0 - ����� 1 - ����
                i = N - 1;
                j = 0;
                for (int k = 0; k < N - 1; k ++) {
                    if (dir == 0) {
                        j += 1;
                        arr[i][j] = rand() % (N * N) + 1;
                       
                        for (int st = 0; st < N - 1; st++) {
                            i -= 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        dir = 1;
                    }
                    else {

                        j += 1;
                        arr[i][j] = rand() % (N * N) + 1;

                        for (int st = 0; st < N - 1; st++) {
                            i += 1;
                            arr[i][j] = rand() % (N * N) + 1;
                        }
                        dir = 0;
                    }
                    cout << "\n";
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++)
                            cout << arr[i][j] << " ";
                        cout << "\n";
                    }
                    cout << "\n";
                }

                break;
            }

            case 2: {
                int N;
                cout << "�������� ������ �������(6,8,10): ";
                cin >> N;
                int** arr = new int* [N];
                for (int i = 0; i < N; i++) {
                    arr[i] = new int[N];
                }
                srand(time(NULL)); 
                
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        *(*(arr + i) + j) = i * N + j + 1;
                    }
                }
                

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        std::cout << arr[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                cout << '\n';
                // 1 2 
                // 3 4
                for (int i = 0; i < N / 2; i++) {//1 2
                    for (int j = 0; j < N / 2; j++) {
                        swap(*(*(arr + i) + j + N/2), *(*(arr + i) + j));
                    }
                }
                for (int i = N / 2; i < N; i++) { //1 3
                    for (int j = 0; j < N / 2; j++) {
                        swap(*(*(arr + i - N / 2) + j), *(*(arr + i) + j));
                    }
                }
            
                for (int i = N / 2; i < N; i++) { // 3 4
                    for (int j = N / 2; j < N; j++) {
                        swap(*(*(arr + i) + j - N/2), *(*(arr + i) + j));
                    }
                }
                
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        std::cout << arr[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                cout << '\n';

                for (int i = 0; i < N / 2; i++) { // 1 4
                    for (int j = 0; j < N / 2; j++) {
                        swap(*(*(arr + i) + j), *(*(arr + i + N/2) + j + N/2));
                    }
                }
                for (int i = 0; i < N / 2; i++) { // 2 3
                    for (int j = N/2; j < N; j++) {
                        swap(*(*(arr + i) + j), *(*(arr + i + N / 2) + j - N / 2));
                    }
                }
                
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        std::cout << arr[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                cout << '\n';

                for (int i = N / 2; i < N; i++) { //1 3 � 2 4
                    for (int j = 0; j < N; j++) {
                        swap(*(*(arr + i - N / 2) + j), *(*(arr + i) + j));
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        std::cout << arr[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                cout << '\n';

                for (int i = 0; i < N; i++) {//1 2 � 3 4
                    for (int j = 0; j < N / 2; j++) {
                        swap(*(*(arr + i) + j + N / 2), *(*(arr + i) + j));
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        std::cout << arr[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                cout << '\n';
                break;
            }
            case 3: {
                int N;
                cout << "�������� ������ �������(6,8,10): ";
                cin >> N;

                int** arr = new int* [N];
                for (int i = 0; i < N; i++) {
                    arr[i] = new int[N];
                    for (int j = 0; j < N; j++) {
                        arr[i][j] = 0;
                    }
                }

                srand(time(NULL)); 

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        arr[i][j] = rand() % (N * N) + 1;
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr[i][j] << " ";
                    cout << "\nn";
                }

                int row1, row2, col1, col2;
                for (int i = 0; i < N*N; i++) {
                    for (int j = i - 1; j > 0; j--) {
                        row2 = j / N;
                        col2 = j % N;
                        row1 = (j - 1) / N;
                        col1 = (j - 1) % N;
                        if (*(*(arr + row1) + col1) > *(*(arr + row2) + col2)) {
                            swap(*(*(arr + row1) + col1), *(*(arr + row2) + col2));
                        }
                        else {
                            break;
                        }
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr[i][j] << " ";
                    cout << "\n";
                }
            }

            case 4: {
                int N = 0;
                cout << "�������� ������ �������(6,8,10): ";
                cin >> N;
                int my_number = 0;
                char sign = 0;
                cout << "������� �����:\n";
                cin >> my_number;
                cout << "������� ���� ��������:\n";
                cin >> sign;
                int** arr = new int*[N];
                for (int i = 0; i < N; i++) {
                    arr[i] = new int[N];
                }

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        *(*(arr + i) + j) = i * N + j + 1;
                    }
                }
                cout << "\n";
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr[i][j] << " ";
                    cout << "\n";
                }

                cout << "\n";
                switch (sign) {
                case '+': {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            *(*(arr + i) + j) += my_number;
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                }
                case '-': {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            *(*(arr + i) + j) -= my_number;
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                }
                case '/': {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            *(*(arr + i) + j) /= my_number;
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                }
                case '*': {
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            *(*(arr + i) + j) *= my_number;
                            std::cout << arr[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    break;
                    }

                    }
                    break;
                }
            

            case 5: {
                int N;
                cout << "�������� ������ �������: ";
                cin >> N;
                int** arr1 = new int* [N];
                int** arr2 = new int* [N];
                int** resArr = new int* [N];
                for (int i = 0; i < N; i++) {
                    arr1[i] = new int[N];
                    arr2[i] = new int[N];
                    resArr[i] = new int[N];
                }
                srand(time(NULL)); 

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        *(*(arr1 + i) + j) = rand() % (N * N) + 1;
                        *(*(arr2 + i) + j) = rand() % (N * N) + 1;
                    }
                }

                cout << "\n\n������ �������:\n\n";

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr1[i][j] << " ";
                    cout << "\n";
                }

                cout << "\n\n������ �������:\n\n";

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << arr2[i][j] << " ";
                    cout << "\n";
                }

                cout << "\n\n�����:\n\n";
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        resArr[i][j] = arr1[i][j] + arr2[i][j];
                        cout << arr1[i][j] << " + " << arr2[i][j] << " = " << resArr[i][j] << " ";
                    }
                    cout << "\n";
                }

                cout << "\n\n���������:\n\n";

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        cout << resArr[i][j] << " ";
                    cout << "\n";
                }


                break;
            }
            }
            }
                  return 0;
            }
            