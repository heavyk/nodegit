#ifndef GITTAG_H
#define GITTAG_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/object.h"
#include "../include/signature.h"
#include "../include/strarray.h"
// Forward declaration.
struct git_tag {
};

using namespace node;
using namespace v8;

class GitTag : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_tag *GetValue();
    git_tag **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                                                 

  private:


    GitTag(git_tag *raw, bool selfFreeing);
    ~GitTag();
                                                                                 
    static NAN_METHOD(JSNewFunction);


    struct AnnotationCreateBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      const git_signature * tagger;
      const char * message;
    };
    class AnnotationCreateWorker : public Nan::AsyncWorker {
      public:
        AnnotationCreateWorker(
            AnnotationCreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~AnnotationCreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        AnnotationCreateBaton *baton;
    };

    static NAN_METHOD(AnnotationCreate);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      const git_signature * tagger;
      const char * message;
      int force;
    };
    class CreateWorker : public Nan::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateBaton *baton;
    };

    static NAN_METHOD(Create);

    struct CreateLightweightBaton {
      int error_code;
      const git_error* error;
      git_oid * oid;
      git_repository * repo;
      const char * tag_name;
      const git_object * target;
      int force;
    };
    class CreateLightweightWorker : public Nan::AsyncWorker {
      public:
        CreateLightweightWorker(
            CreateLightweightBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateLightweightWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateLightweightBaton *baton;
    };

    static NAN_METHOD(CreateLightweight);

    struct DeleteBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * tag_name;
    };
    class DeleteWorker : public Nan::AsyncWorker {
      public:
        DeleteWorker(
            DeleteBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DeleteWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DeleteBaton *baton;
    };

    static NAN_METHOD(Delete);

    static NAN_METHOD(Free);

    static NAN_METHOD(Id);

    struct ListBaton {
      int error_code;
      const git_error* error;
      git_strarray * tag_names;
      git_repository * repo;
    };
    class ListWorker : public Nan::AsyncWorker {
      public:
        ListWorker(
            ListBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ListWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ListBaton *baton;
    };

    static NAN_METHOD(List);

    static NAN_METHOD(ListMatch);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_tag * out;
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
      git_tag * out;
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

    static NAN_METHOD(Message);

    static NAN_METHOD(Name);

    static NAN_METHOD(Owner);

    static NAN_METHOD(Peel);

    static NAN_METHOD(Tagger);

    static NAN_METHOD(Target);

    static NAN_METHOD(TargetId);

    static NAN_METHOD(TargetType);
    git_tag *raw;
};

#endif
