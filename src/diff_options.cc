// This is a generated file, modify: generate/templates/struct_content.cc.
#include <nan.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/functions/copy.h"
#include "../include/diff_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/strarray.h"
  #include "../include/diff.h"
  #include "../include/diff_delta.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitDiffOptions::GitDiffOptions() {
   git_diff_options wrappedValue = GIT_DIFF_OPTIONS_INIT;
   this->raw = (git_diff_options*) malloc(sizeof(git_diff_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_diff_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitDiffOptions::GitDiffOptions(git_diff_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitDiffOptions::~GitDiffOptions() {
             if (this->notify_cb != NULL) {
    delete this->notify_cb;
    this->raw->notify_payload = NULL;
  }
                          
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitDiffOptions::ConstructFields() {
                  Local<Object> pathspecTemp = GitStrarray::New(
            &this->raw->pathspec,
            false
          )->ToObject();
          this->pathspec.Reset(pathspecTemp);

   
          // Set the static method call and set the payload for this function to be
          // the current instance
          this->raw->notify_cb = NULL;
          this->raw->notify_payload = (void *)this;
          this->notify_cb = NULL;
   
          Local<Value> notify_payload = Nan::Undefined();
          this->notify_payload.Reset(notify_payload);
                     }

void GitDiffOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("DiffOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("flags").ToLocalChecked(), GetFlags, SetFlags);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ignoreSubmodules").ToLocalChecked(), GetIgnoreSubmodules, SetIgnoreSubmodules);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("pathspec").ToLocalChecked(), GetPathspec, SetPathspec);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("notifyCb").ToLocalChecked(), GetNotifyCb, SetNotifyCb);
          Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("contextLines").ToLocalChecked(), GetContextLines, SetContextLines);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("interhunkLines").ToLocalChecked(), GetInterhunkLines, SetInterhunkLines);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("idAbbrev").ToLocalChecked(), GetIdAbbrev, SetIdAbbrev);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("maxSize").ToLocalChecked(), GetMaxSize, SetMaxSize);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("oldPrefix").ToLocalChecked(), GetOldPrefix, SetOldPrefix);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("newPrefix").ToLocalChecked(), GetNewPrefix, SetNewPrefix);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("DiffOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitDiffOptions::JSNewFunction) {
  GitDiffOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitDiffOptions();
  }
  else {
    instance = new GitDiffOptions(static_cast<git_diff_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitDiffOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitDiffOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_diff_options *GitDiffOptions::GetValue() {
  return this->raw;
}

git_diff_options **GitDiffOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitDiffOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitDiffOptions::GetVersion) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitDiffOptions::SetVersion) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffOptions::GetFlags) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->flags));
     }

    NAN_SETTER(GitDiffOptions::SetFlags) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->flags = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffOptions::GetIgnoreSubmodules) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->ignore_submodules));

     }

    NAN_SETTER(GitDiffOptions::SetIgnoreSubmodules) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->ignore_submodules = (git_submodule_ignore_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitDiffOptions::GetPathspec) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->pathspec));

     }

    NAN_SETTER(GitDiffOptions::SetPathspec) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        Local<Object> pathspec(value->ToObject());

        wrapper->pathspec.Reset(pathspec);

        wrapper->raw->pathspec = * StrArrayConverter::Convert(pathspec->ToObject()) ;

     }

      NAN_GETTER(GitDiffOptions::GetNotifyCb) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->notify_cb != NULL) {
          info.GetReturnValue().Set(wrapper->notify_cb->GetFunction());
        } else {
          info.GetReturnValue().SetUndefined();
        }

     }

    NAN_SETTER(GitDiffOptions::SetNotifyCb) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->notify_cb != NULL) {
          delete wrapper->notify_cb;
        }

        if (value->IsFunction()) {
          if (!wrapper->raw->notify_cb) {
            wrapper->raw->notify_cb = (git_diff_notify_cb)notify_cb_cppCallback;
          }

          wrapper->notify_cb = new Nan::Callback(value.As<Function>());
        }

     }

      int GitDiffOptions::notify_cb_cppCallback (
          const git_diff * diff_so_far,           git_diff_delta * delta_to_add,           const char * matched_pathspec,           void * payload        ) {
        NotifyCbBaton* baton = new NotifyCbBaton();

          baton->diff_so_far = diff_so_far;
          baton->delta_to_add = delta_to_add;
          baton->matched_pathspec = matched_pathspec;
          baton->payload = payload;
 
        baton->result = 0;
        baton->req.data = baton;
        baton->done = false;

        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) notify_cb_async);
        uv_async_send(&baton->req);

        while(!baton->done) {
          sleep_for_ms(1);
        }

  
        return baton->result;
      }

      void GitDiffOptions::notify_cb_async(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
        GitDiffOptions* instance = static_cast<GitDiffOptions*>(baton->   payload  );

        if (instance->notify_cb->IsEmpty()) {
            baton->result = 1; // no results acquired
 
          baton->done = true;
          return;
        }

              if (baton->matched_pathspec == NULL) {
              baton->matched_pathspec = "";
          }
    
        Local<Value> argv[4] = {
                GitDiff::New((void *)baton->diff_so_far, false),
                  GitDiffDelta::New((void *)baton->delta_to_add, false),
                  Nan::New(baton->matched_pathspec).ToLocalChecked(),
                Nan::New(instance->notify_payload)
          };

        Nan::TryCatch tryCatch;
        Local<v8::Value> result = instance->notify_cb->Call(4, argv);

        if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
          Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

          if (thenProp->IsFunction()) {
            // we can be reasonbly certain that the result is a promise
            Local<Object> promise = result->ToObject();

            baton->promise.Reset(promise);

            uv_close((uv_handle_t*) &baton->req, (uv_close_cb) notify_cb_setupAsyncPromisePolling);
            return;
          }
        }

          if (result.IsEmpty() || result->IsNativeError()) {
            baton->result = -1;
          }
          else if (!result->IsNull() && !result->IsUndefined()) {
             if (result->IsNumber()) {
              baton->result = (int)result->ToNumber()->Value();
            }
            else {
              baton->result = 1;
            }
           }
          else {
            baton->result = 1;
          }
         baton->done = true;
        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      void GitDiffOptions::notify_cb_setupAsyncPromisePolling(uv_async_t* req) {
        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
        uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) notify_cb_asyncPromisePolling);
        uv_async_send(&baton->req);
      }

      void GitDiffOptions::notify_cb_asyncPromisePolling(uv_async_t* req, int status) {
        Nan::HandleScope scope;

        NotifyCbBaton* baton = static_cast<NotifyCbBaton*>(req->data);
        Local<Object> promise = Nan::New<Object>(baton->promise);

        Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
        Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

        if (isPending->Value()) {
          uv_async_send(&baton->req);
          return;
        }

        Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
        Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

        if (isFulfilled->Value()) {
          Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> result = resultFn->Call(promise, 0, argv);

            if (result.IsEmpty() || result->IsNativeError()) {
              baton->result = -1;
            }
            else if (!result->IsNull() && !result->IsUndefined()) {
               if (result->IsNumber()) {
                baton->result = (int)result->ToNumber()->Value();
              }
              else{
                baton->result = 1;
              }
             }
            else {
              baton->result = 1;
            }
           baton->done = true;
        }
        else {
          // promise was rejected
          GitDiffOptions* instance = static_cast<GitDiffOptions*>(baton->   payload  );
          Local<v8::Object> parent = instance->handle();
          Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
          Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
          parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

          baton->result = -1;
          baton->done = true;
        }

        uv_close((uv_handle_t*) &baton->req, NULL);
      }
      NAN_GETTER(GitDiffOptions::GetNotifyPayload) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->notify_payload));

     }

    NAN_SETTER(GitDiffOptions::SetNotifyPayload) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        wrapper->notify_payload.Reset(value);

     }

      NAN_GETTER(GitDiffOptions::GetContextLines) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->context_lines));
     }

    NAN_SETTER(GitDiffOptions::SetContextLines) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->context_lines = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffOptions::GetInterhunkLines) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->interhunk_lines));
     }

    NAN_SETTER(GitDiffOptions::SetInterhunkLines) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->interhunk_lines = (uint32_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffOptions::GetIdAbbrev) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->id_abbrev));
     }

    NAN_SETTER(GitDiffOptions::SetIdAbbrev) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->id_abbrev = (uint16_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitDiffOptions::GetMaxSize) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->max_size));

     }

    NAN_SETTER(GitDiffOptions::SetMaxSize) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->max_size = (git_off_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitDiffOptions::GetOldPrefix) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->GetValue()->old_prefix) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->old_prefix).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitDiffOptions::SetOldPrefix) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->GetValue()->old_prefix) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->old_prefix = strdup(*str);

     }

      NAN_GETTER(GitDiffOptions::GetNewPrefix) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->GetValue()->new_prefix) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->new_prefix).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitDiffOptions::SetNewPrefix) {

      GitDiffOptions *wrapper = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info.This());

        if (wrapper->GetValue()->new_prefix) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->new_prefix = strdup(*str);

     }

   
Nan::Persistent<Function> GitDiffOptions::constructor_template;
