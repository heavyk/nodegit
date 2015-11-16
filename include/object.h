#ifndef GITOBJECT_H
#define GITOBJECT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/buf.h"
// Forward declaration.
struct git_object {
};

using namespace node;
using namespace v8;

class GitObject : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_object *GetValue();
    git_object **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                         

  private:


    GitObject(git_object *raw, bool selfFreeing);
    ~GitObject();
                                                         
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Size);

    struct DupBaton {
      int error_code;
      const git_error* error;
      git_object * dest;
      git_object * source;
    };
    class DupWorker : public Nan::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DupBaton *baton;
    };

    static NAN_METHOD(Dup);

    static NAN_METHOD(Free);

    static NAN_METHOD(Id);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_object * object;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      git_otype type;
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

    struct LookupBypathBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      const git_object * treeish;
      const char * path;
      git_otype type;
    };
    class LookupBypathWorker : public Nan::AsyncWorker {
      public:
        LookupBypathWorker(
            LookupBypathBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupBypathWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupBypathBaton *baton;
    };

    static NAN_METHOD(LookupBypath);

    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_object * object_out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
      git_otype type;
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

    struct PeelBaton {
      int error_code;
      const git_error* error;
      git_object * peeled;
      const git_object * object;
      git_otype target_type;
    };
    class PeelWorker : public Nan::AsyncWorker {
      public:
        PeelWorker(
            PeelBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~PeelWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        PeelBaton *baton;
    };

    static NAN_METHOD(Peel);

    struct ShortIdBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_object * obj;
    };
    class ShortIdWorker : public Nan::AsyncWorker {
      public:
        ShortIdWorker(
            ShortIdBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ShortIdWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ShortIdBaton *baton;
    };

    static NAN_METHOD(ShortId);

    static NAN_METHOD(String2type);

    static NAN_METHOD(Type);

    static NAN_METHOD(Type2string);

    static NAN_METHOD(Typeisloose);
    git_object *raw;
};

#endif
