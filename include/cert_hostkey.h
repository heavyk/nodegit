#ifndef GITCERTHOSTKEY_H
#define GITCERTHOSTKEY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitCertHostkey : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cert_hostkey *GetValue();
    git_cert_hostkey **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCertHostkey(git_cert_hostkey *raw, bool selfFreeing);
    ~GitCertHostkey();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(CertType);
    static NAN_METHOD(Type);
    static NAN_METHOD(HashMd5);
    static NAN_METHOD(HashSha1);
    git_cert_hostkey *raw;
};

#endif
