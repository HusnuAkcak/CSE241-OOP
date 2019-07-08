#include <iostream>
#include <list>
#include <vector>
#include <set>

#include "collection.h"
#include "hashSet.cpp"
#include "arrayList.cpp"
#include "linkedList.cpp"
#include "iterator.cpp"

using std::cout;
using std::endl;
using std::list;
using std::set;
using std::vector;

using namespace HusnuAkcak;

int main(){
  list<int>myList;
  list<int>myList2;
  vector<int>myVect;
  vector<int>myVect2;
  set<int>mySet;
  set<int>mySet2;
  int testElm;


  // hashSet CLASS MEMBER FUNCTION TESTS STARTS.
  cout << "'HashSet' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  cout << "::::LIST VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // LIST VERSION OF hashSet
  HashSet<int, list<int> > hs1;

  myList.insert(myList.end(),1);
  myList.insert(myList.end(),2);
  myList.insert(myList.end(),3);
  myList.insert(myList.end(),4);
  myList.insert(myList.end(),5);
  myList.insert(myList.end(),6);
  myList.insert(myList.end(),7);
  myList.insert(myList.end(),7);

  myList2.insert(myList2.end(),10);
  myList2.insert(myList2.end(),20);
  myList2.insert(myList2.end(),30);
  myList2.insert(myList2.end(),40);
  myList2.insert(myList2.end(),50);
  myList2.insert(myList2.end(),60);
  myList2.insert(myList2.end(),70);
  myList2.insert(myList2.end(),70);

  hs1.addAll(myList); // a list added to hashSet 1
  cout << "(list version)hashSet::[addAll] function is tested\n";
  //single elements are being added to hashSet 1
  hs1.add(100);
  hs1.add(101);
  hs1.add(102);
  cout << "(list version)hashSet::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(hs1.contains(testElm))
    cout << testElm<< " contained by the hs1 collection\n";
  else
    cout << testElm<< " is not contained by the hs1 collection\n";
  cout << "(list version)hashSet::[contains] function is tested\n";

  cout << "----------------------\n";
  if(hs1.containsAll(myList))
    cout << "myList contained by the hs1 collection\n";
  else
    cout << "myList is not contained by the hs1 collection\n";

  cout << "(list version)hashSet::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "hs1.size "<<hs1.size() <<endl;
  cout << "(list version)hashSet::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(hs1.isEmpty())
    cout << "hs1 collection is empty.\n";
  else
    cout << "hs1 collection is not empty.\n";
  cout << "(list version)hashSet::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test hs1.size "<<hs1.size() <<endl;
  hs1.remove(1);
  cout << "after [remove] test hs1.size "<<hs1.size() <<endl;
  cout << "(list version)hashSet::[remove] function is tested\n";
  cout << "Iterator::remove funciton is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test hs1.size "<<hs1.size() <<endl;
  cout << "hs1 content\n";
  auto it0=hs1.iterator();
  for (; it0.hasNext(); it0.next())
    cout<< *it0 <<", ";
  cout <<endl;
  try{
    cout<< *it0<<endl;
  }
  catch (domain_error){
    cout<< ":::::::::::DOMAIN_ERROR::::::::::\n";
  }
  cout<< "Iterator::*() exception is caught\n";
  cout << "myList content\n";
  for (auto it=myList.begin(); it!=myList.end(); ++it)
    cout<< *it <<", ";
  cout <<endl;
  hs1.removeAll(myList);
  cout << "after [removeAll] test hs1.size "<<hs1.size() <<endl;
  cout << "hs1 content\n";
  for (auto it=hs1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)hashSet::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  hs1.addAll(myList2);
  hs1.add(55);
  hs1.add(44);
  cout << "new elements are added to hs1 \n";
  cout << "before [retainAll] test hs1.size "<<hs1.size() <<endl;
  cout << "hs1 content\n";
  for (auto it=hs1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList2 content\n";
  for (auto it=myList2.begin(); it!=myList2.end(); ++it)
    cout<< *it <<", ";
  cout <<endl;
  hs1.retainAll(myList2);
  cout << "after [retainAll] test hs1.size "<<hs1.size() <<endl;
  cout << "hs1 content\n";
  auto it=hs1.iterator();
  for (; it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  try{
    cout<< *it<<endl;
  }
  catch (domain_error){
    cout<< ":::::::::::DOMAIN_ERROR::::::::::\n";
  }
  cout<< "Iterator::*() exception is caught\n";
  cout << "(list version)hashSet::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(list version)hashSet is being printed to the screen\n";
  auto itr=hs1.iterator(); //iterator() funciton is tested;
  cout << "(list version)hashSet::[iterator] function is tested\n";
  while(itr.hasNext()) {
    cout<< *itr <<endl;
    itr.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear hs1.size "<<hs1.size() <<endl;
  hs1.clear();
  cout << "after clear hs1.size "<<hs1.size() <<endl;
  cout << "(list version)hashSet::[clear] function is tested\n";
  cout << "----------------------\n";
  cout << "::::LIST VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";

  cout << "::::VECTOR VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // VECTOR VERSION OF hashSet
  HashSet<int, vector<int> > hs2;

  myVect.insert(myVect.end(),1);
  myVect.insert(myVect.end(),2);
  myVect.insert(myVect.end(),3);
  myVect.insert(myVect.end(),4);
  myVect.insert(myVect.end(),5);
  myVect.insert(myVect.end(),6);
  myVect.insert(myVect.end(),7);
  myVect.insert(myVect.end(),7);


  myVect2.insert(myVect2.end(),10);
  myVect2.insert(myVect2.end(),20);
  myVect2.insert(myVect2.end(),30);
  myVect2.insert(myVect2.end(),40);
  myVect2.insert(myVect2.end(),50);
  myVect2.insert(myVect2.end(),60);
  myVect2.insert(myVect2.end(),70);
  myVect2.insert(myVect2.end(),70);

  hs2.addAll(myVect); // a list added to hashSet 1
  cout << "(vector version)hashSet::[addAll] function is tested\n";
  //single elements are being added to hashSet 1
  hs2.add(100);
  hs2.add(101);
  hs2.add(102);
  cout << "(vector version)hashSet::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(hs2.contains(testElm))
    cout << testElm<< " contained by the hs2 collection\n";
  else
    cout << testElm<< " is not contained by the hs2 collection\n";
  cout << "(vector version)hashSet::[contains] function is tested\n";

  cout << "----------------------\n";
  if(hs2.containsAll(myVect))
    cout << "myVect contained by the hs2 collection\n";
  else
    cout << "myVect is not contained by the hs2 collection\n";

  cout << "(vector version)hashSet::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "hs2.size "<<hs2.size() <<endl;
  cout << "(vector version)hashSet::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(hs2.isEmpty())
    cout << "hs2 collection is empty.\n";
  else
    cout << "hs2 collection is not empty.\n";
  cout << "(vector version)hashSet::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test hs2.size "<<hs2.size() <<endl;
  hs2.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test hs2.size "<<hs2.size() <<endl;
  cout << "(vector version)hashSet::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test hs2.size "<<hs2.size() <<endl;
  cout << "hs2 content\n";
  for (auto it=hs2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect content\n";
  for (auto it=myVect.begin(); it!=myVect.end(); ++it)
    cout<< *it <<", ";
  cout <<endl;
  hs2.removeAll(myVect);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test hs2.size "<<hs2.size() <<endl;
  cout << "hs2 content\n";
  for (auto it=hs2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)hashSet::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  hs2.addAll(myVect2);
  hs2.add(55);
  hs2.add(44);
  cout << "new elements are added to hs2 \n";
  cout << "before [retainAll] test hs2.size "<<hs2.size() <<endl;
  cout << "hs2 content\n";
  for (auto it=hs2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect2 content\n";
  for (auto it=myVect2.begin(); it!=myVect2.end(); ++it)
    cout<< *it <<", ";
  cout <<endl;
  hs2.retainAll(myVect2);
  cout << "after [retainAll] test hs2.size "<<hs2.size() <<endl;
  cout << "hs2 content\n";
  for (auto it=hs2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)hashSet::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(vector version)hashSet is being printed to the screen\n";
  auto itr2=hs2.iterator(); //iterator() funciton is tested;
  cout << "(vector version)hashSet::[iterator] function is tested\n";
  while(itr2.hasNext()) {
    cout<< *itr2 <<endl;
    itr2.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear hs2.size "<<hs2.size() <<endl;
  hs2.clear();
  cout << "after clear hs2.size "<<hs2.size() <<endl;
  cout << "(vector version)hashSet::[clear] function is tested\n";
  cout << "----------------------\n";
  cout << "::::VECTOR VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";
  cout << "::::SET VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // SET VERSION OF hashSet
  HashSet<int, set<int> > hs3;

  mySet.insert(mySet.end(),1);
  mySet.insert(mySet.end(),2);
  mySet.insert(mySet.end(),3);
  mySet.insert(mySet.end(),4);
  mySet.insert(mySet.end(),5);
  mySet.insert(mySet.end(),6);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);


  mySet2.insert(mySet2.end(),10);
  mySet2.insert(mySet2.end(),20);
  mySet2.insert(mySet2.end(),30);
  mySet2.insert(mySet2.end(),40);
  mySet2.insert(mySet2.end(),50);
  mySet2.insert(mySet2.end(),60);
  mySet2.insert(mySet2.end(),70);
  mySet2.insert(mySet2.end(),70);

  hs3.addAll(mySet); // a list added to hashSet 1
  cout << "(set version)hashSet::[addAll] function is tested\n";
  //single elements are being added to hashSet 1
  hs3.add(100);
  hs3.add(101);
  hs3.add(102);
  cout << "(set version)hashSet::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(hs3.contains(testElm))
    cout << testElm<< " contained by the hs3 collection\n";
  else
    cout << testElm<< " is not contained by the hs3 collection\n";
  cout << "(set version)hashSet::[contains] function is tested\n";

  cout << "----------------------\n";
  if(hs3.containsAll(mySet))
    cout << "mySet contained by the hs3 collection\n";
  else
    cout << "mySet is not contained by the hs3 collection\n";

  cout << "(set version)hashSet::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "hs3.size "<<hs3.size() <<endl;
  cout << "(set version)hashSet::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(hs3.isEmpty())
    cout << "hs3 collection is empty.\n";
  else
    cout << "hs3 collection is not empty.\n";
  cout << "(set version)hashSet::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test hs3.size "<<hs3.size() <<endl;
  hs3.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test hs3.size "<<hs3.size() <<endl;
  cout << "(set version)hashSet::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test hs3.size "<<hs3.size() <<endl;
  cout << "hs3 content\n";
  for (auto it=hs3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (auto it=mySet.begin(); it!=mySet.end(); ++it)
    cout<< *it <<", ";
  cout <<endl;
  hs3.removeAll(mySet);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test hs3.size "<<hs3.size() <<endl;
  cout << "hs3 content\n";
  for (auto it=hs3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)hashSet::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  hs3.addAll(mySet2);
  hs3.add(55);
  hs3.add(44);
  cout << "new elements are added to hs3 \n";
  cout << "before [retainAll] test hs3.size "<<hs3.size() <<endl;
  hs3.retainAll(mySet2);
  cout << "after [retainAll] test hs3.size "<<hs3.size() <<endl;
  cout << "(set version)hashSet::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(set version)hashSet is being printed to the screen\n";
  auto itr3 = hs3.iterator(); //iterator() funciton is tested;
  cout << "(set version)hashSet::[iterator] function is tested\n";
  while(itr3.hasNext()) {
    cout<< *(itr3) <<endl;
    itr3.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";
  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear hs3.size "<<hs3.size() <<endl;
  hs3.clear();
  cout << "after clear hs3.size "<<hs3.size() <<endl;
  cout << "(set version)hashSet::[clear] function is tested\n";
  cout << "----------------------\n";

  cout << "::::SET VERSION 'HashSet' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";
  cout << "'HashSet' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "===============================================================\n";
  cout << "===============================================================\n";
  cout << "===============================================================\n\n";

  // ArrayList CLASS MEMBER FUNCTION TESTS STARTS.
  cout << "'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  cout << "::::LIST VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // LIST VERSION OF ArrayList
  ArrayList<int, list<int> > al1;

  myList.clear();
  myList.insert(myList.end(),1);
  myList.insert(myList.end(),2);
  myList.insert(myList.end(),3);
  myList.insert(myList.end(),4);
  myList.insert(myList.end(),5);
  myList.insert(myList.end(),6);
  myList.insert(myList.end(),7);
  myList.insert(myList.end(),7);


  myList2.clear();
  myList2.insert(myList2.end(),10);
  myList2.insert(myList2.end(),20);
  myList2.insert(myList2.end(),30);
  myList2.insert(myList2.end(),40);
  myList2.insert(myList2.end(),50);
  myList2.insert(myList2.end(),60);
  myList2.insert(myList2.end(),70);
  myList2.insert(myList2.end(),70);

  al1.addAll(myList); // a list added to ArrayList 1
  cout << "al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList content\n";
  for (auto it=myList.begin(); it!=myList.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(list version)ArrayList::[addAll] function is tested\n";
  //single elements are being added to ArrayList 1
  al1.add(100);
  al1.add(101);
  al1.add(102);
  cout << "after add operation al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)ArrayList::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(al1.contains(testElm))
    cout << testElm<< " contained by the al1 collection\n";
  else
    cout << testElm<< " is not contained by the al1 collection\n";
  cout << "(list version)ArrayList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(al1.containsAll(myList))
    cout << "myList contained by the al1 collection\n";
  else
    cout << "myList is not contained by the al1 collection\n";

  cout << "(list version)ArrayList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "al1.size "<<al1.size() <<endl;
  cout << "(list version)ArrayList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(al1.isEmpty())
    cout << "al1 collection is empty.\n";
  else
    cout << "al1 collection is not empty.\n";
  cout << "(list version)ArrayList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test al1.size "<<al1.size() <<endl;
  al1.remove(1);
  cout << "after [remove] test al1.size "<<al1.size() <<endl;
  cout << "(list version)ArrayList::[remove] function is tested\n";
  cout << "Iterator::remove funciton is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test al1.size "<<al1.size() <<endl;
  cout << "al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList content\n";
  for (auto it=myList.begin(); it!=myList.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  al1.removeAll(myList);
  cout << "after [removeAll] test al1.size "<<al1.size() <<endl;
  cout << "al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)ArrayList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  al1.addAll(myList2);
  al1.add(55);
  al1.add(44);
  cout << "new elements are added to al1 \n";
  cout << "before [retainAll] test al1.size "<<al1.size() <<endl;
  cout << "al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList2 content\n";
  for (auto it=myList2.begin(); it!=myList2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  al1.retainAll(myList2);
  cout << "after [retainAll] test al1.size "<<al1.size() <<endl;
  cout << "al1 content\n";
  for (auto it=al1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)ArrayList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(list version)ArrayList is being printed to the screen\n";
  auto alItr=al1.iterator(); //iterator() funciton is tested;
  cout << "(list version)ArrayList::[iterator] function is tested\n";
  while(alItr.hasNext()) {
    cout<< *alItr <<endl;
    alItr.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear al1.size "<<al1.size() <<endl;
  al1.clear();
  cout << "after clear al1.size "<<al1.size() <<endl;
  cout << "(list version)ArrayList::[clear] function is tested\n";
  cout << "----------------------\n";
  cout << "::::LIST VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";

  cout << "::::VECTOR VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // VECTOR VERSION OF ArrayList
  ArrayList<int, vector<int> > al2;

  myVect.clear();
  myVect.insert(myVect.end(),1);
  myVect.insert(myVect.end(),2);
  myVect.insert(myVect.end(),3);
  myVect.insert(myVect.end(),4);
  myVect.insert(myVect.end(),5);
  myVect.insert(myVect.end(),6);
  myVect.insert(myVect.end(),7);


  myVect2.clear();
  myVect2.insert(myVect2.end(),10);
  myVect2.insert(myVect2.end(),20);
  myVect2.insert(myVect2.end(),30);
  myVect2.insert(myVect2.end(),40);
  myVect2.insert(myVect2.end(),50);
  myVect2.insert(myVect2.end(),60);
  myVect2.insert(myVect2.end(),70);
  myVect2.insert(myVect2.end(),70);

  al2.addAll(myVect); // a list added to ArrayList 1
  cout << "al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect content\n";
  for (auto it=myVect.begin(); it!=myVect.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(vector version)ArrayList::[addAll] function is tested\n";
  //single elements are being added to ArrayList 1
  al2.add(100);
  al2.add(101);
  al2.add(102);
  cout << "after add operation al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)ArrayList::[add] function is tested\n";
  cout << "----------------------\n";

  testElm=100;
  if(al2.contains(testElm))
    cout << testElm<< " contained by the al2 collection\n";
  else
    cout << testElm<< " is not contained by the al2 collection\n";
  cout << "(vector version)ArrayList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(al2.containsAll(myVect))
    cout << "myVect contained by the al2 collection\n";
  else
    cout << "myVect is not contained by the al2 collection\n";

  cout << "(vector version)ArrayList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "al2.size "<<al2.size() <<endl;
  cout << "(vector version)ArrayList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(al2.isEmpty())
    cout << "al2 collection is empty.\n";
  else
    cout << "al2 collection is not empty.\n";
  cout << "(vector version)ArrayList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test al2.size "<<al2.size() <<endl;
  al2.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test al2.size "<<al2.size() <<endl;
  cout << "(vector version)ArrayList::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  al2.add(7);
  al2.add(7);
  al2.add(7);
  cout << "before [removeAll] test al2.size "<<al2.size() <<endl;
  cout << "al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect content\n";
  for (vector<int>::iterator it=myVect.begin(); it!=myVect.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  al2.removeAll(myVect);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test al2.size "<<al2.size() <<endl;
  cout << "al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)ArrayList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  al2.addAll(myVect2);
  al2.add(55);
  al2.add(44);
  cout << "new elements are added to al2 \n";
  cout << "before [retainAll] test al2.size "<<al2.size() <<endl;
  cout << "al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect2 content\n";
  for (vector<int>::iterator it=myVect2.begin(); it!=myVect2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;

  al2.retainAll(myVect2);
  cout << "after [retainAll] test al2.size "<<al2.size() <<endl;
  cout << "al2 content\n";
  for (auto it=al2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)ArrayList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(vector version)ArrayList is being printed to the screen\n";
  auto alItr2=al2.iterator(); //iterator() funciton is tested;
  cout << "(vector version)ArrayList::[iterator] function is tested\n";
  while(alItr2.hasNext()) {
    cout<< *alItr2 <<endl;
    alItr2.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear al2.size "<<al2.size() <<endl;
  al2.clear();
  cout << "after clear al2.size "<<al2.size() <<endl;
  cout << "(vector version)ArrayList::[clear] function is tested\n";
  cout << "----------------------\n";
  cout << "::::VECTOR VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";
  cout << "::::SET VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // SET VERSION OF ArrayList
  ArrayList<int, set<int> > al3;

  mySet.clear();
  mySet.insert(mySet.end(),1);
  mySet.insert(mySet.end(),2);
  mySet.insert(mySet.end(),3);
  mySet.insert(mySet.end(),4);
  mySet.insert(mySet.end(),5);
  mySet.insert(mySet.end(),6);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);


  mySet2.clear();
  mySet2.insert(mySet2.end(),10);
  mySet2.insert(mySet2.end(),20);
  mySet2.insert(mySet2.end(),30);
  mySet2.insert(mySet2.end(),40);
  mySet2.insert(mySet2.end(),50);
  mySet2.insert(mySet2.end(),60);
  mySet2.insert(mySet2.end(),70);
  mySet2.insert(mySet2.end(),70);

  al3.addAll(mySet); // a list added to ArrayList 1
  cout << "al3 content\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (auto it=mySet.begin(); it!=mySet.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(set version)ArrayList::[addAll] function is tested\n";
  //single elements are being added to ArrayList 1
  al3.add(100);
  al3.add(101);
  al3.add(102);
  cout << "after add operation al3 content\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)ArrayList::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(al3.contains(testElm))
    cout << testElm<< " contained by the al3 collection\n";
  else
    cout << testElm<< " is not contained by the al3 collection\n";
  cout << "(set version)ArrayList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(al3.containsAll(mySet))
    cout << "mySet contained by the al3 collection\n";
  else
    cout << "mySet is not contained by the al3 collection\n";

  cout << "(set version)ArrayList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "al3.size "<<al3.size() <<endl;
  cout << "(set version)ArrayList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(al3.isEmpty())
    cout << "al3 collection is empty.\n";
  else
    cout << "al3 collection is not empty.\n";
  cout << "(set version)ArrayList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test al3.size "<<al3.size() <<endl;
  al3.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test al3.size "<<al3.size() <<endl;
  cout << "(set version)ArrayList::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test al3.size "<<al3.size() <<endl;
  cout << "al3 content:\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (set<int>::iterator it=mySet.begin(); it!=mySet.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  al3.removeAll(mySet);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test al3.size "<<al3.size() <<endl;
  cout << "al3 content:\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)ArrayList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  al3.addAll(mySet2);
  al3.add(55);
  al3.add(44);
  cout << "new elements are added to al3 \n";
  cout << "before [retainAll] test al3.size "<<al3.size() <<endl;
  cout << "al3 content\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (set<int>::iterator it=mySet2.begin(); it!=mySet2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  al3.retainAll(mySet2);
  cout << "after [retainAll] test al3.size "<<al3.size() <<endl;
  cout << "al3 content\n";
  for (auto it=al3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)ArrayList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(set version)ArrayList is being printed to the screen\n";
  auto alItr3 = al3.iterator(); //iterator() funciton is tested;
  cout << "(set version)ArrayList::[iterator] function is tested\n";
  while(alItr3.hasNext()) {
    cout<< *(alItr3) <<endl;
    alItr3.next();
  }

  try{
    cout<< *alItr3<<endl;
  }
  catch (domain_error){
    cout<< ":::::::::::DOMAIN_ERROR::::::::::\n";
  }
  cout << "Iterator:: *() fucntion exception is caught\n";
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";
  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear al3.size "<<al3.size() <<endl;
  al3.clear();
  cout << "after clear al3.size "<<al3.size() <<endl;
  cout << "(set version)ArrayList::[clear] function is tested\n";
  cout << "----------------------\n";

  cout << "::::SET VERSION 'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";
  cout << "'ArrayList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "===============================================================\n";
  cout << "===============================================================\n";
  cout << "===============================================================\n\n";

  // LinkedList CLASS MEMBER FUNCTION TESTS STARTS.
  cout << "'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  cout << "::::LIST VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // LIST VERSION OF LinkedList
  LinkedList<int, list<int> > ll1;

  myList.clear();
  myList.insert(myList.end(),1);
  myList.insert(myList.end(),2);
  myList.insert(myList.end(),3);
  myList.insert(myList.end(),4);
  myList.insert(myList.end(),5);
  myList.insert(myList.end(),6);
  myList.insert(myList.end(),7);
  myList.insert(myList.end(),7);


  myList2.clear();
  myList2.insert(myList2.end(),10);
  myList2.insert(myList2.end(),20);
  myList2.insert(myList2.end(),30);
  myList2.insert(myList2.end(),40);
  myList2.insert(myList2.end(),50);
  myList2.insert(myList2.end(),60);
  myList2.insert(myList2.end(),70);
  myList2.insert(myList2.end(),70);

  ll1.addAll(myList); // a list added to LinkedList 1
  cout << "ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList content\n";
  for (auto it=myList.begin(); it!=myList.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(list version)LinkedList::[addAll] function is tested\n";
  //single elements are being added to LinkedList 1
  ll1.add(100);
  ll1.add(101);
  ll1.add(102);
  cout << "after add operation ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)LinkedList::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(ll1.contains(testElm))
    cout << testElm<< " contained by the ll1 collection\n";
  else
    cout << testElm<< " is not contained by the ll1 collection\n";
  cout << "(list version)LinkedList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(ll1.containsAll(myList))
    cout << "myList contained by the ll1 collection\n";
  else
    cout << "myList is not contained by the ll1 collection\n";

  cout << "(list version)LinkedList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "ll1.size "<<ll1.size() <<endl;
  cout << "(list version)LinkedList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(ll1.isEmpty())
    cout << "ll1 collection is empty.\n";
  else
    cout << "ll1 collection is not empty.\n";
  cout << "(list version)LinkedList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test ll1.size "<<ll1.size() <<endl;
  ll1.remove(1);
  cout << "after [remove] test ll1.size "<<ll1.size() <<endl;
  cout << "(list version)LinkedList::[remove] function is tested\n";
  cout << "Iterator::remove funciton is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test ll1.size "<<ll1.size() <<endl;
  cout << "ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList content\n";
  for (auto it=myList.begin(); it!=myList.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  ll1.removeAll(myList);
  cout << "after [removeAll] test ll1.size "<<ll1.size() <<endl;
  cout << "ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)LinkedList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll1.addAll(myList2);
  ll1.add(55);
  ll1.add(44);
  cout << "new elements are added to ll1 \n";
  cout << "before [retainAll] test ll1.size "<<ll1.size() <<endl;
  cout << "ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myList2 content\n";
  for (auto it=myList2.begin(); it!=myList2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  ll1.retainAll(myList2);
  cout << "after [retainAll] test ll1.size "<<ll1.size() <<endl;
  cout << "ll1 content\n";
  for (auto it=ll1.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(list version)LinkedList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll1.offer(testElm);
  cout << testElm<< " offered to the linkedList\n";
  cout << "(set version)LinkedList::[offer] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "head of list : "<<ll1.element()<<endl;
  cout << "(set version)LinkedList::[element] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll1.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout << "(list version)LinkedList::[poll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(list version)LinkedList is being printed to the screen\n";
  auto llItr=ll1.iterator(); //iterator() funciton is tested;
  cout << "(list version)LinkedList::[iterator] function is tested\n";
  while(llItr.hasNext()) {
    cout<< *llItr <<endl;
    llItr.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear ll1.size "<<ll1.size() <<endl;
  ll1.clear();
  cout << "after clear ll1.size "<<ll1.size() <<endl;
  cout << "(list version)LinkedList::[clear] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll1.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout <<"------------------------\n";

  cout << "::::LIST VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";

  cout << "::::VECTOR VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // VECTOR VERSION OF LinkedList
  LinkedList<int, vector<int> > ll2;

  myVect.clear();
  myVect.insert(myVect.end(),1);
  myVect.insert(myVect.end(),2);
  myVect.insert(myVect.end(),3);
  myVect.insert(myVect.end(),4);
  myVect.insert(myVect.end(),5);
  myVect.insert(myVect.end(),6);
  myVect.insert(myVect.end(),7);


  myVect2.clear();
  myVect2.insert(myVect2.end(),10);
  myVect2.insert(myVect2.end(),20);
  myVect2.insert(myVect2.end(),30);
  myVect2.insert(myVect2.end(),40);
  myVect2.insert(myVect2.end(),50);
  myVect2.insert(myVect2.end(),60);
  myVect2.insert(myVect2.end(),70);
  myVect2.insert(myVect2.end(),70);

  ll2.addAll(myVect); // a list added to LinkedList 1
  cout << "ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect content\n";
  for (auto it=myVect.begin(); it!=myVect.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(vector version)LinkedList::[addAll] function is tested\n";
  //single elements are being added to LinkedList 1
  ll2.add(100);
  ll2.add(101);
  ll2.add(102);
  cout << "after add operation ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)LinkedList::[add] function is tested\n";
  cout << "----------------------\n";

  testElm=100;
  if(ll2.contains(testElm))
    cout << testElm<< " contained by the ll2 collection\n";
  else
    cout << testElm<< " is not contained by the ll2 collection\n";
  cout << "(vector version)LinkedList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(ll2.containsAll(myVect))
    cout << "myVect contained by the ll2 collection\n";
  else
    cout << "myVect is not contained by the ll2 collection\n";

  cout << "(vector version)LinkedList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "ll2.size "<<ll2.size() <<endl;
  cout << "(vector version)LinkedList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(ll2.isEmpty())
    cout << "ll2 collection is empty.\n";
  else
    cout << "ll2 collection is not empty.\n";
  cout << "(vector version)LinkedList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test ll2.size "<<ll2.size() <<endl;
  ll2.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test ll2.size "<<ll2.size() <<endl;
  cout << "(vector version)LinkedList::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll2.add(7);
  ll2.add(7);
  ll2.add(7);
  cout << "before [removeAll] test ll2.size "<<ll2.size() <<endl;
  cout << "ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect content\n";
  for (vector<int>::iterator it=myVect.begin(); it!=myVect.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  ll2.removeAll(myVect);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test ll2.size "<<ll2.size() <<endl;
  cout << "ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)LinkedList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll2.addAll(myVect2);
  ll2.add(55);
  ll2.add(44);
  cout << "new elements are added to ll2 \n";
  cout << "before [retainAll] test ll2.size "<<ll2.size() <<endl;
  cout << "ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "myVect2 content\n";
  for (vector<int>::iterator it=myVect2.begin(); it!=myVect2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;

  ll2.retainAll(myVect2);
  cout << "after [retainAll] test ll2.size "<<ll2.size() <<endl;
  cout << "ll2 content\n";
  for (auto it=ll2.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(vector version)LinkedList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll2.offer(testElm);
  cout << testElm<< " offered to the linkedList\n";
  cout << "(vector version)LinkedList::[offer] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "head of list : "<<ll2.element()<<endl;
  cout << "(vector version)LinkedList::[element] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll2.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout << "(list version)LinkedList::[poll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(vector version)LinkedList is being printed to the screen\n";
  auto llItr2=ll2.iterator(); //iterator() funciton is tested;
  cout << "(vector version)LinkedList::[iterator] function is tested\n";
  while(llItr2.hasNext()) {
    cout<< *llItr2 <<endl;
    llItr2.next();
  }
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";

  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear ll2.size "<<ll2.size() <<endl;
  ll2.clear();
  cout << "after clear ll2.size "<<ll2.size() <<endl;
  cout << "(vector version)LinkedList::[clear] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll2.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout <<"------------------------\n";

  cout << "::::VECTOR VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";

  cout << "=================================================================\n\n";
  cout << "::::SET VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS STARTS\n";
  // SET VERSION OF LinkedList
  LinkedList<int, set<int> > ll3;

  mySet.clear();
  mySet.insert(mySet.end(),1);
  mySet.insert(mySet.end(),2);
  mySet.insert(mySet.end(),3);
  mySet.insert(mySet.end(),4);
  mySet.insert(mySet.end(),5);
  mySet.insert(mySet.end(),6);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);
  mySet.insert(mySet.end(),7);


  mySet2.clear();
  mySet2.insert(mySet2.end(),10);
  mySet2.insert(mySet2.end(),20);
  mySet2.insert(mySet2.end(),30);
  mySet2.insert(mySet2.end(),40);
  mySet2.insert(mySet2.end(),50);
  mySet2.insert(mySet2.end(),60);
  mySet2.insert(mySet2.end(),70);
  mySet2.insert(mySet2.end(),70);

  ll3.addAll(mySet); // a list added to LinkedList 1
  cout << "ll3 content\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (auto it=mySet.begin(); it!=mySet.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  cout << "(set version)LinkedList::[addAll] function is tested\n";
  //single elements are being added to LinkedList 1
  ll3.add(100);
  ll3.add(101);
  ll3.add(102);
  cout << "after add operation ll3 content\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)LinkedList::[add] function is tested\n";

  cout << "----------------------\n";
  testElm=100;
  if(ll3.contains(testElm))
    cout << testElm<< " contained by the ll3 collection\n";
  else
    cout << testElm<< " is not contained by the ll3 collection\n";
  cout << "(set version)LinkedList::[contains] function is tested\n";

  cout << "----------------------\n";
  if(ll3.containsAll(mySet))
    cout << "mySet contained by the ll3 collection\n";
  else
    cout << "mySet is not contained by the ll3 collection\n";

  cout << "(set version)LinkedList::[containsAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "ll3.size "<<ll3.size() <<endl;
  cout << "(set version)LinkedList::[size] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  if(ll3.isEmpty())
    cout << "ll3 collection is empty.\n";
  else
    cout << "ll3 collection is not empty.\n";
  cout << "(set version)LinkedList::[isEmpty] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [remove] test ll3.size "<<ll3.size() <<endl;
  ll3.remove(1);
  cout << "Iterator::remove function is tested\n";
  cout << "after [remove] test ll3.size "<<ll3.size() <<endl;
  cout << "(set version)LinkedList::[remove] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "before [removeAll] test ll3.size "<<ll3.size() <<endl;
  cout << "ll3 content:\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (set<int>::iterator it=mySet.begin(); it!=mySet.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  ll3.removeAll(mySet);
  cout << "Iterator::remove function is tested\n";
  cout << "after [removeAll] test ll3.size "<<ll3.size() <<endl;
  cout << "ll3 content:\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)LinkedList::[removeAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll3.addAll(mySet2);
  ll3.add(55);
  ll3.add(44);
  cout << "new elements are added to ll3 \n";
  cout << "before [retainAll] test ll3.size "<<ll3.size() <<endl;
  cout << "ll3 content\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "mySet content\n";
  for (set<int>::iterator it=mySet2.begin(); it!=mySet2.end(); ++it)
    cout<<*it<<", ";
  cout <<endl;
  ll3.retainAll(mySet2);
  cout << "after [retainAll] test ll3.size "<<ll3.size() <<endl;
  cout << "ll3 content\n";
  for (auto it=ll3.iterator(); it.hasNext(); it.next())
    cout<< *it <<", ";
  cout <<endl;
  cout << "(set version)LinkedList::[retainAll] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  ll3.offer(testElm);
  cout << testElm<< " offered to the linkedList\n";
  cout << "(set version)LinkedList::[offer] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  cout << "head of list : "<<ll3.element()<<endl;
  cout << "(set version)LinkedList::[element] function is tested\n";
  cout << "----------------------\n";

  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll3.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout << "(set version)LinkedList::[poll] function is tested\n";
  cout << "----------------------\n";

  cout << "--------------------------------------------------------\n";
  cout << "(set version)LinkedList is being printed to the screen\n";
  auto llItr3 = ll3.iterator(); //iterator() funciton is tested;
  cout << "(set version)LinkedList::[iterator] function is tested\n";
  while(llItr3.hasNext()) {
    cout<< *(llItr3) <<endl;
    llItr3.next();
  }

  try{
    cout<< *llItr3<<endl;
  }
  catch (domain_error){
    cout<< ":::::::::::DOMAIN_ERROR::::::::::\n";
  }
  cout << "Iterator:: *() fucntion exception is caught\n";
  cout << "Iterator::hasNext function is tested\n";
  cout << "Iterator::next function is tested\n";
  cout << "Iterator::operator *() function is tested\n";
  cout << "--------------------------------------------------------\n";

  cout << "----------------------\n";
  cout << "before clear ll3.size "<<ll3.size() <<endl;
  ll3.clear();
  cout << "after clear ll3.size "<<ll3.size() <<endl;
  cout << "(set version)LinkedList::[clear] function is tested\n";
  cout << "----------------------\n";


  cout << "----------------------\n";
  try{
    cout << "head of list : "<<ll3.poll()<<endl;
  }
  catch(out_of_range){
    cout << "You are out of range\n";
  }
  cout << "exception control is done for 'poll' function\n";
  cout <<"------------------------\n";

  cout << "::::SET VERSION 'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";
  cout << "'LinkedList' TEMPLATE CLASS FUCNTIONS TESTS ENDS\n\n";
  return 0;
}
