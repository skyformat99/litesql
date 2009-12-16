#ifndef generator_hpp
#define generator_hpp

#include <vector>
#include <ostream>

#include "objectmodel.hpp"


namespace litesql {
  class CodeGenerator {

  public:
    virtual ~CodeGenerator();

    virtual void setOutputDirectory(const std::string& directory);
    virtual const std::string& getOutputDirectory() const;
    
    //void setOutputFile(const std::string& file);
    //const std::string& getOutputFilename() const;

    virtual const char* getTarget() const;
    virtual bool generateCode(const ObjectModel* model)=0;

    bool generate(ostream& os,const std::vector<xml::Object* >& objects,size_t indent=2);
    bool generate(ostream& os,const std::vector<xml::Relation* >& relations,size_t indent=2);
    //virtual void generate(std::ostream& os,const ObjectModel* model,size_t indent=0);

    virtual bool generate(std::ostream& os,xml::Object* const object    , size_t indent=2) {return true;};
    //virtual void generate(std::ostream& os,xml::Field* field     , size_t indent=4){};
    //virtual void generate(std::ostream& os,xml::Method* pMethod  , size_t indent=4){};

    virtual bool generate(std::ostream& os,xml::Relation* const relation,size_t indent=4){return true;};

    static CodeGenerator* create(const char* target);

  protected:
    CodeGenerator(const char* target)
      : m_target(target) {};

  private:
    const char* m_target;

    std::string m_drive;
    std::string m_filename;
    std::string m_directory;
  };

  class CompositeGenerator : public CodeGenerator {
  public:
    CompositeGenerator(): CodeGenerator("composite") { };
  
    void setOutputDirectory(const std::string& directory);
    const std::string& getOutputDirectory() const;
    void add(CodeGenerator* g);
    bool generateCode(const ObjectModel* model);
  private:
    std::vector<CodeGenerator*> generators;
  };

}

#endif //#ifndef generator_hpp

