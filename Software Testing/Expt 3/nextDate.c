#include<stdio.h>
#include<stdbool.h>

bool isLeap(int y) {
  if (y%100==0 && y%400==0) return 1;
  else if (y%4==0 && y%100!=0) return 1;
  else return 0;
}
int main() {
  int m,d,y;
  printf("Enter Date, Month and Year: ");
  scanf("%d%d%d", &d, &m, &y);
  if (d<1 || d>31) return 0;
  if (m<1 || m>12) return 0;
  if (y<1812 || y>2012) return 0;
  if (m==2) {
    if (isLeap) {
      if (d>29) {
        printf("Invalid Date");
        return 0;
      }
      else if (d<29)
        d++;
      else if (d==29) {
        d = 1;
        m++;
      }
    }
    else {
      if (d>28) {
        printf("Invalid Date");
        return 0;
      }
      else if (d<28)
        d++;
      else if (d==28) {
        d = 1;
        m++;
      }
    }
  }
  else if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) {
    if (d==31) {
      d=1;
      m++;
      if (m==12){
        y++;
        m=1;
      }
    }
    else
      d++;
  }
  else if (m==4||m==6||m==9||m==11) {
    if (d == 30) {
      d=1;
      m++;
    }
    else
      d++;
  }
  printf("Next date: %d/%d/%d", d,m,y);
  return 0;
}
