#ifndef GITCERT_H
#define GITCERT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitCert : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cert *GetValue();
    git_cert **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCert(git_cert *raw, bool selfFreeing);
    ~GitCert();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(CertType);
    git_cert *raw;
};

#endif
