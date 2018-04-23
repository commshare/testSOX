#include "common/packet.h"
//using namespace sox;

struct TestData: public sox::Marshallable
{
  enum { SIZE = 4 };
public:
  TestData(void)
    : id(0)
    , type(0)
    , payload(NULL)
    , length(0)
  {
  }

  virtual void marshal(sox::Pack &pak) const
  {
    pak << m_strName;
    return;
  }

  virtual void unmarshal(const sox::Unpack &pak)
  {
    pak >> id >> type;
    pak >> m_strName;
  };
  void showValue(){
        std::cout<<"id "<<id<<"type "<<type<<" m_strName "<<m_strName<<std::endl;
  }

public:
  uint16_t    id;
  uint16_t    type;
  const char* payload;
  uint32_t    length;
  std::string m_strName;
};

int main(){
    TestData t=new TestData();
    
    getchar();
    return 0;
}
