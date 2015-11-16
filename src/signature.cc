// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/signature.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/time.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitSignature::GitSignature(git_signature *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitSignature::~GitSignature() {
      if (this->selfFreeing) {
        git_signature_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                          }

  void GitSignature::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Signature").ToLocalChecked());

           Nan::SetMethod(tpl, "default", Default);
            Nan::SetPrototypeMethod(tpl, "dup", Dup);
            Nan::SetPrototypeMethod(tpl, "free", Free);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "now", Now);
           Nan::SetPrototypeMethod(tpl, "name", Name);
         Nan::SetPrototypeMethod(tpl, "email", Email);
         Nan::SetPrototypeMethod(tpl, "when", When);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Signature").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitSignature::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitSignature cannot be instantiated.");
     }

    GitSignature* object = new GitSignature(static_cast<git_signature *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitSignature::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitSignature::constructor_template), 2, argv).ToLocalChecked());
  }

  git_signature *GitSignature::GetValue() {
    return this->raw;
  }

  git_signature **GitSignature::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitSignature::ClearValue() {
    this->raw = NULL;
  }

  
/*
  * @param Repository repo
     * @return Signature out    */
NAN_METHOD(GitSignature::Default) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 git_signature_default(
&out
,from_repo
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param Signature callback
   */
NAN_METHOD(GitSignature::Dup) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DupBaton* baton = new DupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->sig = Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  DupWorker *worker = new DupWorker(baton, callback);
  worker->SaveToPersistent("sig", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitSignature::DupWorker::Execute() {
  int result = git_signature_dup(
&baton->dest,baton->sig    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitSignature::DupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->dest != NULL) {
    // GitSignature baton->dest
       to = GitSignature::New((void *)baton->dest, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method dup has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
     */
NAN_METHOD(GitSignature::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue() != NULL) {
 git_signature_free(
Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
  * @param String name
   * @param String email
   * @param Number time
   * @param Number offset
     * @return Signature out    */
NAN_METHOD(GitSignature::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number time is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number offset is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email;

  String::Utf8Value email(info[1]->ToString());
  from_email = (const char *) strdup(*email);
// end convert_from_v8 block
// start convert_from_v8 block
  git_time_t from_time;
  from_time = (git_time_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_offset;
  from_offset = (int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
 git_signature_new(
&out
,from_name
,from_email
,from_time
,from_offset
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param String name
   * @param String email
     * @return Signature out    */
NAN_METHOD(GitSignature::Now) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

  git_signature * out = 0;
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email;

  String::Utf8Value email(info[1]->ToString());
  from_email = (const char *) strdup(*email);
// end convert_from_v8 block
 git_signature_now(
&out
,from_name
,from_email
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitSignature out
       to = GitSignature::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
       NAN_METHOD(GitSignature::Name) {
      Local<v8::Value> to;

       char *
         name =
         Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->name;
 // start convert_to_v8 block
  if (name){
       to = Nan::New<String>(name).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitSignature::Email) {
      Local<v8::Value> to;

       char *
         email =
         Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->email;
 // start convert_to_v8 block
  if (email){
       to = Nan::New<String>(email).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitSignature::When) {
      Local<v8::Value> to;

       git_time
        *
          when =
        &
          Nan::ObjectWrap::Unwrap<GitSignature>(info.This())->GetValue()->when;
 // start convert_to_v8 block
  
  if (when != NULL) {
    // GitTime when
       to = GitTime::New((void *)when, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitSignature::constructor_template;
 