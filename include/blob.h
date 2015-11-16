#ifndef GITBLOB_H
#define GITBLOB_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/wrapper.h"
#include "node_buffer.h"
#include "../include/oid.h"
#include "../include/repository.h"
// Forward declaration.
struct git_blob {
};

using namespace node;
using namespace v8;

class GitBlob : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_blob *GetValue();
    git_blob **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                              

  private:


    GitBlob(git_blob *raw, bool selfFreeing);
    ~GitBlob();
                                              
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(CreateFrombuffer);

    static NAN_METHOD(CreateFromdisk);

    static NAN_METHOD(CreateFromworkdir);

    static NAN_METHOD(Free);

    static NAN_METHOD(Id);

    static NAN_METHOD(IsBinary);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_blob * blob;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
    };
    class LookupWorker : public Nan::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupBaton *baton;
    };

    static NAN_METHOD(Lookup);

    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_blob * blob;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
    };
    class LookupPrefixWorker : public Nan::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupPrefixWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupPrefixBaton *baton;
    };

    static NAN_METHOD(LookupPrefix);

    static NAN_METHOD(Owner);

    static NAN_METHOD(Rawcontent);

    static NAN_METHOD(Rawsize);
    git_blob *raw;
};

#endif
