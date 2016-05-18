#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

string ItoS(int I)
{
    string R = "000";
    R[2] = I%10 + '0';
    I /= 10;
    R[1] = I%10 + '0';
    I /= 10;
    R[0] = I%10 + '0';

    return R;
}
int main()
{
    int N, runCommand;
    char d, n,s,a;
    char instr[5];

    scanf("%d", &N);
    fgets(instr, sizeof(instr), stdin);
    fgets(instr, sizeof(instr), stdin);

    bool halt = false;
    string instructions[1000];
    int pc;

    for (int i=0; i< N; i++)
    {
        for (int j=0; j<1000; j++) instructions[j] = "000";
        pc=0;

        while(fgets(instr, sizeof(instr), stdin) != NULL)
        {

            if (instr[0] == '\n') break;
            instructions[pc][0] = instr[0];
            instructions[pc][1] = instr[1];
            instructions[pc][2] = instr[2];
            pc++;
        }

        int reg[10];
        for (int j=0; j<10; j++) reg[j] = 0;
        runCommand =0;
        halt = false;
        pc=0;


        while(!halt)
        {
            runCommand++;
            int op1 = int(instructions[pc][1] - '0');
            int op2 = int(instructions[pc][2] - '0');

            switch(instructions[pc][0])
            {
                case '1':
                    halt = true;
                    pc++;
                    break;
                case '2':
                    reg[op1] = op2;
                    pc++;
                    break;
                case '3':
                    reg[op1] = (reg[op1] + op2) % 1000;
                    pc++;
                    break;
                case '4':
                    reg[op1] = (reg[op1] * op2) % 1000;
                    pc++;
                    break;
                case '5':
                    reg[op1] = reg[op2];
                    pc++;
                    break;
                case '6':
                    reg[op1] = (reg[op1] + reg[op2]) % 1000;
                    pc++;
                    break;
                case '7':
                    reg[op1] = (reg[op1] * reg[op2]) % 1000;
                    pc++;
                    break;
                case '8':
                    reg[op1] = std::stoi(instructions[reg[op2]]);
                    pc++;
                    break;
                case '9':
                    instructions[reg[op2]] = ItoS(reg[op1]);
                    pc++;
                    break;
                case '0':
                    if (reg[op2] != 0)
                        pc = reg[op1];
                    else
                        pc++;
                    break;
            }

        }
        cout << runCommand << endl;
        if (i < N-1) cout << endl;
    }

    return 0;
}
