#include <vector>
#include <iostream>

int main()
{
  std::vector<unsigned int> vect={100,1000,10000,100000};
  unsigned int moy,i;
  for (i = 0; i < vect.size(); i++)
  {
    moy += vect.at(i);
  }
  moy/=vect.size();
  std::cout<<"Moyenne : "<<moy<<"\n";
  if (moy>50)
  {
    std::cout<<"moy>50\n";
  }                                                                                                                                                                                                                                                                                                                       else
  std::cout<<"fini !\n";
  return 0;
}
