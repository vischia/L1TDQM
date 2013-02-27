/**   
      \class	    testBlockingClass testBlockingClass.cc "UserCode/Vischia/L1DQMDevCode/bin/testBlockingClass.cc"                                                                     
      \brief    executable for testing that the offline L1T blocking class satisfy the specifications requested
      
      \author   Pietro Vischia
      
      \version  $Id: testBlockingClass.cc,v 1.1 2013/02/27 17:48:55 vischia Exp $                                                                                                       
*/

#include "Vischia/L1DQMDevCode/interface/L1TLSBlock.h"

// System includes	

// CMSSW includes

// ROOT includes



/*
  
@run me like this

testBlockingClass

*/
using namespace std;

//
int main(int argc, char* argv[])
{
  cout<<endl<<"Testing Blocking algorithm"<<endl;

  L1TLSBlock* blocker = new L1TLSBlock(); // Instantiate object
  cout<<endl<<"Blocker object has been instantiated"<<endl;

  
  L1TLSBlock::LumiTestDoubleList doubleList; doubleList.clear(); // Building doubleList.
  // It is not ordered by LS in order to test the class ordering algo
  doubleList.push_back( make_pair(   1,   23.      ) );
  doubleList.push_back( make_pair(   9,   14.      ) );
  doubleList.push_back( make_pair(  11,  345.34    ) );
  doubleList.push_back( make_pair(  10,    1.2     ) );
  doubleList.push_back( make_pair(  12,   43.53    ) );
  doubleList.push_back( make_pair(  32,    1.2     ) );
  doubleList.push_back( make_pair(  13,   44.      ) );
  doubleList.push_back( make_pair(  14,   25.      ) );
  doubleList.push_back( make_pair(   2,   25.6     ) );
  doubleList.push_back( make_pair(  31, 2313.535   ) );
  doubleList.push_back( make_pair(   5, 1231.41234 ) );
  doubleList.push_back( make_pair(  15,  124.553   ) );
  doubleList.push_back( make_pair(   4,  314.34143 ) );
  doubleList.push_back( make_pair(  29,   42.35    ) );
  doubleList.push_back( make_pair(  30,   88.43    ) );
  doubleList.push_back( make_pair(   6,   53.57    ) );
  doubleList.push_back( make_pair(  25,   34.24    ) );
  doubleList.push_back( make_pair(   7,   12.56    ) );
  doubleList.push_back( make_pair(  26,   15.47    ) );
  doubleList.push_back( make_pair(  27,  613.34    ) );
  doubleList.push_back( make_pair(   8,   35.35    ) );
  doubleList.push_back( make_pair(  28, 3535.66    ) );
  doubleList.push_back( make_pair(  24,   72.235   ) );
  doubleList.push_back( make_pair(  23,   25.48    ) );
  doubleList.push_back( make_pair(  22, 2564.      ) );
  doubleList.push_back( make_pair(   3,   57.      ) );
  doubleList.push_back( make_pair(  19,  246.      ) );
  doubleList.push_back( make_pair(  20,   36.      ) );
  doubleList.push_back( make_pair(  18,   35.23    ) );
  doubleList.push_back( make_pair(  21,    7.3     ) );
  doubleList.push_back( make_pair(  17,  646.3     ) );
  doubleList.push_back( make_pair(  16,    32.46    ) );
  doubleList.push_back( make_pair(  33,    32.46    ) );
  doubleList.push_back( make_pair(  34,    32.46    ) );
  doubleList.push_back( make_pair(  35,    32.46    ) );
  cout<<endl<<"Input list content:"<<endl;
  cout<<endl<<"\t\t LS \t STAT"<<endl;
  for(size_t i=0; i<doubleList.size(); i++)
    cout<<"\t\t" << doubleList[i].first << " \t " << doubleList[i].second << endl;
  
  cout<<endl<<"Block by statistics with a threshold error of 0.31 per block"<<endl;
  cout<<"\t Expected behaviour: [1-10], [11-32] have enough stat, [33-35] must be merged:"<<endl;
  L1TLSBlock::LumiRangeList smallRange = blocker->doBlocking(doubleList, 0.31, L1TLSBlock::BLOCKBY::STATISTICS); // Block by statistics with a threshold of 50.543 per block
  cout<<endl<<"Resulting LumiRange vector:"<<endl;
  cout<<endl<<"\t\t start \t end"<<endl;
  for(size_t i=0; i<smallRange.size(); i++)
    cout<<"\t\t" << smallRange[i].first << " \t " << smallRange[i].second << endl;


  cout<<endl<<"Block by statistics with a threshold of 0.99 per block:"<<endl;
  cout<<"\t Expected behaviour: run has a single range [1-35] without enough stat, but the single range is still added "<<endl;
  L1TLSBlock::LumiRangeList largeRange = blocker->doBlocking(doubleList, 0.99, L1TLSBlock::BLOCKBY::STATISTICS); // Block by statistics with a threshold of 1000. per block
  cout<<endl<<"Resulting LumiRange vector:"<<endl;
  cout<<endl<<"\t\t start \t end"<<endl;
  for(size_t i=0; i<largeRange.size(); i++)
    cout<<"\t\t" << largeRange[i].first << " \t " << largeRange[i].second << endl;

  
  cout << "testBlockingClass reached its natural end" << endl;
  
  return 0;
  
}


