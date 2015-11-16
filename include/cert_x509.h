#ifndef GITCERTX509_H
#define GITCERTX509_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/wrapper.h"
#include "node_buffer.h"

using namespace node;
using namespace v8;

class GitCertX509 : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cert_x509 *GetValue();
    git_cert_x509 **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCertX509(git_cert_x509 *raw, bool selfFreeing);
    ~GitCertX509();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(CertType);
    static NAN_METHOD(Data);
    static NAN_METHOD(Len);
    git_cert_x509 *raw;
};

#endif
