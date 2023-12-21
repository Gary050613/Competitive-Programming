#include <bits/stdc++.h>
using namespace std;
map<char, double> qwerty2, qwerty1, dvorak;

void init(){
    qwerty2['`']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['1']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['2']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['3']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['4']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['5']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['6']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['7']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['8']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['9']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['0']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['-']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['=']=sqrt(pow(2, 2) + pow(2, 2));

    qwerty2['q']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['w']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['e']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['r']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['t']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['y']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['u']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['i']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['o']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['p']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['[']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2[']']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty2['\\']=sqrt(pow(1, 2) + pow(3, 2));

    qwerty2['a']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['s']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['d']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['f']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['g']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty2['h']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty2['j']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['k']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['l']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2[';']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['\'']=sqrt(pow(0, 2) + pow(1, 2));

    qwerty2['z']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['x']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['c']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['v']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['b']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['n']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['m']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2[',']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['.']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['/']=sqrt(pow(1, 2) + pow(0, 2));

    qwerty2['~']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['!']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['@']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['#']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['$']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['%']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['^']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['&']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['*']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['(']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2[')']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty2['_']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty2['+']=sqrt(pow(2, 2) + pow(2, 2));

    qwerty2['Q']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['W']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['E']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['R']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['T']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['Y']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['U']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['I']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['O']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['P']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['{']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['}']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty2['|']=sqrt(pow(1, 2) + pow(3, 2));

    qwerty2['A']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['S']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['D']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['F']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['G']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty2['H']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty2['J']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['K']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['L']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2[':']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty2['"']=sqrt(pow(0, 2) + pow(1, 2));

    qwerty2['Z']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['X']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['C']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['V']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['B']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['N']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty2['M']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['<']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['>']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty2['?']=sqrt(pow(1, 2) + pow(0, 2));

    qwerty1['`']=sqrt(pow(2, 2) + pow(4, 2));
    qwerty1['1']=sqrt(pow(2, 2) + pow(3, 2));
    qwerty1['2']=sqrt(pow(2, 2) + pow(2, 2));
    qwerty1['3']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty1['4']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['5']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['6']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['7']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['8']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty1['9']=sqrt(pow(2, 2) + pow(2, 2));
    qwerty1['0']=sqrt(pow(2, 2) + pow(3, 2));
    qwerty1['-']=sqrt(pow(2, 2) + pow(4, 2));
    qwerty1['=']=sqrt(pow(2, 2) + pow(5, 2));

    qwerty1['q']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['w']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['e']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['r']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['t']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['y']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['u']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['i']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['o']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['p']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['[']=sqrt(pow(1, 2) + pow(4, 2));
    qwerty1[']']=sqrt(pow(1, 2) + pow(5, 2));
    qwerty1['\\']=sqrt(pow(1, 2) + pow(6, 2));

    qwerty1['a']=sqrt(pow(0, 2) + pow(3, 2));
    qwerty1['s']=sqrt(pow(0, 2) + pow(2, 2));
    qwerty1['d']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty1['f']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['g']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['h']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['j']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['k']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty1['l']=sqrt(pow(0, 2) + pow(2, 2));
    qwerty1[';']=sqrt(pow(0, 2) + pow(3, 2));
    qwerty1['\'']=sqrt(pow(0, 2) + pow(4, 2));

    qwerty1['z']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['x']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['c']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['v']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['b']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['n']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['m']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1[',']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['.']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['/']=sqrt(pow(1, 2) + pow(3, 2));

    qwerty1['~']=sqrt(pow(2, 2) + pow(4, 2));
    qwerty1['!']=sqrt(pow(2, 2) + pow(3, 2));
    qwerty1['@']=sqrt(pow(2, 2) + pow(2, 2));
    qwerty1['#']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty1['$']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['%']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['^']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['&']=sqrt(pow(2, 2) + pow(0, 2));
    qwerty1['*']=sqrt(pow(2, 2) + pow(1, 2));
    qwerty1['(']=sqrt(pow(2, 2) + pow(2, 2));
    qwerty1[')']=sqrt(pow(2, 2) + pow(3, 2));
    qwerty1['_']=sqrt(pow(2, 2) + pow(4, 2));
    qwerty1['+']=sqrt(pow(2, 2) + pow(5, 2));

    qwerty1['Q']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['W']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['E']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['R']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['T']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['Y']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['U']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['I']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['O']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['P']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['{']=sqrt(pow(1, 2) + pow(4, 2));
    qwerty1['}']=sqrt(pow(1, 2) + pow(5, 2));
    qwerty1['|']=sqrt(pow(1, 2) + pow(6, 2));

    qwerty1['A']=sqrt(pow(0, 2) + pow(3, 2));
    qwerty1['S']=sqrt(pow(0, 2) + pow(2, 2));
    qwerty1['D']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty1['F']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['G']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['H']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['J']=sqrt(pow(0, 2) + pow(0, 2));
    qwerty1['K']=sqrt(pow(0, 2) + pow(1, 2));
    qwerty1['L']=sqrt(pow(0, 2) + pow(2, 2));
    qwerty1[':']=sqrt(pow(0, 2) + pow(3, 2));
    qwerty1['"']=sqrt(pow(0, 2) + pow(4, 2));

    qwerty1['Z']=sqrt(pow(1, 2) + pow(3, 2));
    qwerty1['X']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['C']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['V']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['B']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['N']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['M']=sqrt(pow(1, 2) + pow(0, 2));
    qwerty1['<']=sqrt(pow(1, 2) + pow(1, 2));
    qwerty1['>']=sqrt(pow(1, 2) + pow(2, 2));
    qwerty1['?']=sqrt(pow(1, 2) + pow(3, 2));

    dvorak['`']=sqrt(pow(2, 2) + pow(5, 2));
    dvorak['1']=sqrt(pow(2, 2) + pow(4, 2));
    dvorak['2']=sqrt(pow(2, 2) + pow(3, 2));
    dvorak['3']=sqrt(pow(2, 2) + pow(2, 2));
    dvorak['q']=sqrt(pow(2, 2) + pow(1, 2));
    dvorak['j']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['l']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['m']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['f']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['p']=sqrt(pow(2, 2) + pow(1, 2));
    dvorak['/']=sqrt(pow(2, 2) + pow(2, 2));
    dvorak['[']=sqrt(pow(2, 2) + pow(3, 2));
    dvorak[']']=sqrt(pow(2, 2) + pow(4, 2));

    dvorak['4']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['5']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['6']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak['.']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['o']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['r']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['s']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['u']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['y']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['b']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak[';']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['=']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['\\']=sqrt(pow(1, 2) + pow(5, 2));

    dvorak['7']=sqrt(pow(0, 2) + pow(4, 2));
    dvorak['8']=sqrt(pow(0, 2) + pow(3, 2));
    dvorak['9']=sqrt(pow(0, 2) + pow(2, 2));
    dvorak['a']=sqrt(pow(0, 2) + pow(1, 2));
    dvorak['e']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['h']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['t']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['d']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['c']=sqrt(pow(0, 2) + pow(1, 2));
    dvorak['k']=sqrt(pow(0, 2) + pow(2, 2));
    dvorak['-']=sqrt(pow(0, 2) + pow(3, 2));

    dvorak['0']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['z']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['x']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak[',']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['i']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['n']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['w']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['v']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['g']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['\'']=sqrt(pow(1, 2) + pow(2, 2));

    dvorak['~']=sqrt(pow(2, 2) + pow(5, 2));
    dvorak['!']=sqrt(pow(2, 2) + pow(4, 2));
    dvorak['@']=sqrt(pow(2, 2) + pow(3, 2));
    dvorak['#']=sqrt(pow(2, 2) + pow(2, 2));
    dvorak['Q']=sqrt(pow(2, 2) + pow(1, 2));
    dvorak['J']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['L']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['M']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['F']=sqrt(pow(2, 2) + pow(0, 2));
    dvorak['P']=sqrt(pow(2, 2) + pow(1, 2));
    dvorak['?']=sqrt(pow(2, 2) + pow(2, 2));
    dvorak['{']=sqrt(pow(2, 2) + pow(3, 2));
    dvorak['}']=sqrt(pow(2, 2) + pow(4, 2));

    dvorak['$']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['%']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['^']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak['>']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['O']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['R']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['S']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['U']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['Y']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['B']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak[':']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['+']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['|']=sqrt(pow(1, 2) + pow(5, 2));

    dvorak['&']=sqrt(pow(0, 2) + pow(4, 2));
    dvorak['*']=sqrt(pow(0, 2) + pow(3, 2));
    dvorak['(']=sqrt(pow(0, 2) + pow(2, 2));
    dvorak['A']=sqrt(pow(0, 2) + pow(1, 2));
    dvorak['E']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['H']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['T']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['D']=sqrt(pow(0, 2) + pow(0, 2));
    dvorak['C']=sqrt(pow(0, 2) + pow(1, 2));
    dvorak['K']=sqrt(pow(0, 2) + pow(2, 2));
    dvorak['_']=sqrt(pow(0, 2) + pow(3, 2));

    dvorak[')']=sqrt(pow(1, 2) + pow(4, 2));
    dvorak['Z']=sqrt(pow(1, 2) + pow(3, 2));
    dvorak['X']=sqrt(pow(1, 2) + pow(2, 2));
    dvorak['<']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['I']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['N']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['W']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['V']=sqrt(pow(1, 2) + pow(0, 2));
    dvorak['G']=sqrt(pow(1, 2) + pow(1, 2));
    dvorak['"']=sqrt(pow(1, 2) + pow(2, 2));
}

int main(){
    init();
    string in;
    while(getline(cin, in)){
        double q2=0, q1=0, d=0;
        for(int i = 0;i<in.length();i++){
            if(qwerty2.count(in[i])) q2 += qwerty2[in[i]];
            if(qwerty1.count(in[i])) q1 += qwerty1[in[i]];
            if(dvorak.count(in[i])) d += dvorak[in[i]];
        }
        printf("%.2lf %.2lf %.2lf\n", q2*2, q1*2, d*2);
    }
    return 0;
}