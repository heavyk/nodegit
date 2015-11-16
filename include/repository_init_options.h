#ifndef GITREPOSITORYINITOPTIONS_H
#define GITREPOSITORYINITOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

 
using namespace node;
using namespace v8;

class GitRepositoryInitOptions : public Nan::ObjectWrap {
  public:
    GitRepositoryInitOptions(git_repository_init_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_repository_init_options *GetValue();
    git_repository_init_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                 
  private:
    GitRepositoryInitOptions();
    ~GitRepositoryInitOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

   
        static NAN_GETTER(GetMode);
        static NAN_SETTER(SetMode);

   
        static NAN_GETTER(GetWorkdirPath);
        static NAN_SETTER(SetWorkdirPath);

   
        static NAN_GETTER(GetDescription);
        static NAN_SETTER(SetDescription);

   
        static NAN_GETTER(GetTemplatePath);
        static NAN_SETTER(SetTemplatePath);

   
        static NAN_GETTER(GetInitialHead);
        static NAN_SETTER(SetInitialHead);

   
        static NAN_GETTER(GetOriginUrl);
        static NAN_SETTER(SetOriginUrl);

  
    git_repository_init_options *raw;
};

#endif
