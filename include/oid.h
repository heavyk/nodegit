#ifndef GITOID_H
#define GITOID_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitOid : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_oid *GetValue();
    git_oid **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                    

  private:


    GitOid(git_oid *raw, bool selfFreeing);
    ~GitOid();
                                    
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Cmp);

    static NAN_METHOD(Cpy);

    static NAN_METHOD(Equal);

    static NAN_METHOD(Fromstr);

    static NAN_METHOD(Iszero);

    static NAN_METHOD(Ncmp);

    static NAN_METHOD(Strcmp);

    static NAN_METHOD(Streq);

    static NAN_METHOD(TostrS);
    git_oid *raw;
};

#endif
