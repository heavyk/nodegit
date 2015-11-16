#ifndef GITODB_H
#define GITODB_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/odb_object.h"
#include "../include/oid.h"
// Forward declaration.
struct git_odb {
};

using namespace node;
using namespace v8;

class GitOdb : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_odb *GetValue();
    git_odb **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                        

  private:


    GitOdb(git_odb *raw, bool selfFreeing);
    ~GitOdb();
                        
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(AddDiskAlternate);

    static NAN_METHOD(Free);

    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_odb * out;
      const char * objects_dir;
    };
    class OpenWorker : public Nan::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenBaton *baton;
    };

    static NAN_METHOD(Open);

    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_odb_object * out;
      git_odb * db;
      const git_oid * id;
      bool idNeedsFree;
    };
    class ReadWorker : public Nan::AsyncWorker {
      public:
        ReadWorker(
            ReadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ReadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ReadBaton *baton;
    };

    static NAN_METHOD(Read);

    struct WriteBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_odb * odb;
      const void * data;
      size_t len;
      git_otype type;
    };
    class WriteWorker : public Nan::AsyncWorker {
      public:
        WriteWorker(
            WriteBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~WriteWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        WriteBaton *baton;
    };

    static NAN_METHOD(Write);
    git_odb *raw;
};

#endif
