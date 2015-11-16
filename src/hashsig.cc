// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/hashsig.h>
 }

#include "../include/functions/copy.h"
#include "../include/hashsig.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitHashsig::GitHashsig(git_hashsig *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitHashsig::~GitHashsig() {
      if (this->selfFreeing) {
        git_hashsig_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                     }

  void GitHashsig::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Hashsig").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "compare", Compare);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "createFromFile", CreateFromfile);
            Nan::SetPrototypeMethod(tpl, "free", Free);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Hashsig").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitHashsig::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitHashsig cannot be instantiated.");
     }

    GitHashsig* object = new GitHashsig(static_cast<git_hashsig *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitHashsig::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitHashsig::constructor_template), 2, argv).ToLocalChecked());
  }

  git_hashsig *GitHashsig::GetValue() {
    return this->raw;
  }

  git_hashsig **GitHashsig::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitHashsig::ClearValue() {
    this->raw = NULL;
  }

  
/*
       * @return Number  result    */
NAN_METHOD(GitHashsig::Compare) {
  Nan::EscapableHandleScope scope;

   int result = git_hashsig_compare(
Nan::ObjectWrap::Unwrap<GitHashsig>(info.This())->GetValue()
,Nan::ObjectWrap::Unwrap<GitHashsig>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param String buf
   * @param Number buflen
   * @param Number opts
    * @param Hashsig callback
   */
NAN_METHOD(GitHashsig::Create) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String buf is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number buflen is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number opts is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_buf;

  String::Utf8Value buf(info[0]->ToString());
  from_buf = (const char *) strdup(*buf);
// end convert_from_v8 block
  baton->buf = from_buf;
// start convert_from_v8 block
  size_t from_buflen;
  from_buflen = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->buflen = from_buflen;
// start convert_from_v8 block
  git_hashsig_option_t from_opts;
  from_opts = (git_hashsig_option_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("buf", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("buflen", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("opts", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitHashsig::CreateWorker::Execute() {
  int result = git_hashsig_create(
&baton->out,baton->buf,baton->buflen,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitHashsig::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitHashsig baton->out
       to = GitHashsig::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("buf"));
      workerArguments.push(GetFromPersistent("buflen"));
      workerArguments.push(GetFromPersistent("opts"));
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
        Local<v8::Object> err = Nan::Error("Method create has thrown an error.")->ToObject();
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

  free((void *)baton->buf);

  delete baton;
}

  
/*
  * @param String path
   * @param Number opts
    * @param Hashsig callback
   */
NAN_METHOD(GitHashsig::CreateFromfile) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateFromfileBaton* baton = new CreateFromfileBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  git_hashsig_option_t from_opts;
  from_opts = (git_hashsig_option_t)  (int) info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  CreateFromfileWorker *worker = new CreateFromfileWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitHashsig::CreateFromfileWorker::Execute() {
  int result = git_hashsig_create_fromfile(
&baton->out,baton->path,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitHashsig::CreateFromfileWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitHashsig baton->out
       to = GitHashsig::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("opts"));
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
        Local<v8::Object> err = Nan::Error("Method createFromFile has thrown an error.")->ToObject();
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

  free((void *)baton->path);

  delete baton;
}

   
/*
     */
NAN_METHOD(GitHashsig::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitHashsig>(info.This())->GetValue() != NULL) {
 git_hashsig_free(
Nan::ObjectWrap::Unwrap<GitHashsig>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitHashsig>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
      Nan::Persistent<Function> GitHashsig::constructor_template;
 