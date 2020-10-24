#ifndef  TOWERS1_H
#define TOWERS1_H
using namespace std;

void towers(int n, char frompeg, char topeg, char auxpeg){
  if(n==1){
    cout << "move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
    return;
  }
  towers(n-1, frompeg, auxpeg, topeg);
  cout << "move disk " << n << " from peg " << frompeg << " to peg " << topeg << endl;
  towers(n-1, auxpeg, topeg, frompeg);
}
#endif /* TOWERS1_H */
