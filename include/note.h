#ifndef GITNOTE_H
#define GITNOTE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/signature.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/note_iterator.h"
// Forward declaration.
struct git_note {
};

using namespace node;
using namespace v8;

class GitNote : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_note *GetValue();
    git_note **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                      static int Foreach_note_cb_cppCallback (
      const git_oid * blob_id
      ,
       const git_oid * annotated_object_id
      ,
       void * payload
      );

    static void Foreach_note_cb_async(uv_async_t* req, int status);
    static void Foreach_note_cb_setupAsyncPromisePolling(uv_async_t* req);
    static void Foreach_note_cb_asyncPromisePolling(uv_async_t* req, int status);
    struct Foreach_NoteCbBaton {
      const git_oid * blob_id;
      const git_oid * annotated_object_id;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                                     

  private:


    GitNote(git_note *raw, bool selfFreeing);
    ~GitNote();
                                                       
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Author);

    static NAN_METHOD(Committer);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * notes_ref;
      const git_signature * author;
      const git_signature * committer;
      const git_oid * oid;
      bool oidNeedsFree;
      const char * note;
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

    struct ForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * notes_ref;
      git_note_foreach_cb note_cb;
      void * payload;
    };
    class ForeachWorker : public Nan::AsyncWorker {
      public:
        ForeachWorker(
            ForeachBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ForeachWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ForeachBaton *baton;
    };

    static NAN_METHOD(Foreach);

    static NAN_METHOD(Free);

    static NAN_METHOD(Id);

    struct IteratorNewBaton {
      int error_code;
      const git_error* error;
      git_note_iterator * out;
      git_repository * repo;
      const char * notes_ref;
    };
    class IteratorNewWorker : public Nan::AsyncWorker {
      public:
        IteratorNewWorker(
            IteratorNewBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IteratorNewWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IteratorNewBaton *baton;
    };

    static NAN_METHOD(IteratorNew);

    static NAN_METHOD(Message);

    static NAN_METHOD(Next);

    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_note * out;
      git_repository * repo;
      const char * notes_ref;
      const git_oid * oid;
      bool oidNeedsFree;
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

    struct RemoveBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * notes_ref;
      const git_signature * author;
      const git_signature * committer;
      const git_oid * oid;
      bool oidNeedsFree;
    };
    class RemoveWorker : public Nan::AsyncWorker {
      public:
        RemoveWorker(
            RemoveBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RemoveWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RemoveBaton *baton;
    };

    static NAN_METHOD(Remove);

    struct Foreach_globalPayload {
      Nan::Callback * note_cb;

      Foreach_globalPayload() {
        note_cb = NULL;
      }

      ~Foreach_globalPayload() {
        if (note_cb != NULL) {
          delete note_cb;
        }
      }
    };
    git_note *raw;
};

#endif
