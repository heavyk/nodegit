// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/buf.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/git_buf_converter.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitBuf::GitBuf(git_buf *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitBuf::~GitBuf() {
      if (this->selfFreeing) {
        git_buf_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                     }

  void GitBuf::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Buf").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "containsNul", ContainsNul);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "grow", Grow);
            Nan::SetPrototypeMethod(tpl, "isBinary", IsBinary);
            Nan::SetPrototypeMethod(tpl, "set", Set);
           Nan::SetPrototypeMethod(tpl, "ptr", Ptr);
         Nan::SetPrototypeMethod(tpl, "asize", Asize);
         Nan::SetPrototypeMethod(tpl, "size", Size);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Buf").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitBuf::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitBuf cannot be instantiated.");
     }

    GitBuf* object = new GitBuf(static_cast<git_buf *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitBuf::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitBuf::constructor_template), 2, argv).ToLocalChecked());
  }

  git_buf *GitBuf::GetValue() {
    return this->raw;
  }

  git_buf **GitBuf::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitBuf::ClearValue() {
    this->raw = NULL;
  }

  
/*
     * @return Number  result    */
NAN_METHOD(GitBuf::ContainsNul) {
  Nan::EscapableHandleScope scope;

   int result = git_buf_contains_nul(
Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitBuf::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue() != NULL) {
 git_buf_free(
Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
  * @param Number target_size
    * @param Buf callback
   */
NAN_METHOD(GitBuf::Grow) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number target_size is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GrowBaton* baton = new GrowBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->buffer = (git_buf *)malloc(sizeof(git_buf ));;
      baton->buffer->ptr = NULL;
      baton->buffer->size = baton->buffer->asize = 0;
  baton->buffer = (git_buf *)malloc(sizeof(git_buf ));
// start convert_from_v8 block
  size_t from_target_size;
  from_target_size = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->target_size = from_target_size;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  GrowWorker *worker = new GrowWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("target_size", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBuf::GrowWorker::Execute() {
  int result = git_buf_grow(
baton->buffer,baton->target_size    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBuf::GrowWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->buffer) {
    to = Nan::New<String>(baton->buffer->ptr, baton->buffer->size).ToLocalChecked();
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
      workerArguments.push(GetFromPersistent("target_size"));
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
        Local<v8::Object> err = Nan::Error("Method grow has thrown an error.")->ToObject();
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

  git_buf_free(baton->buffer);
  free((void *)baton->buffer);

  delete baton;
}

   
/*
     * @return Number  result    */
NAN_METHOD(GitBuf::IsBinary) {
  Nan::EscapableHandleScope scope;

   int result = git_buf_is_binary(
Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Buffer data
   * @param Number datalen
    * @param Buf callback
   */
NAN_METHOD(GitBuf::Set) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Buffer data is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number datalen is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SetBaton* baton = new SetBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->buffer = (git_buf *)malloc(sizeof(git_buf ));;
      baton->buffer->ptr = NULL;
      baton->buffer->size = baton->buffer->asize = 0;
  baton->buffer = (git_buf *)malloc(sizeof(git_buf ));
// start convert_from_v8 block
  const void * from_data;

  from_data = Buffer::Data(info[0]->ToObject());
// end convert_from_v8 block
  baton->data = from_data;
// start convert_from_v8 block
  size_t from_datalen;
  from_datalen = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->datalen = from_datalen;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  SetWorker *worker = new SetWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("data", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("datalen", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBuf::SetWorker::Execute() {
  int result = git_buf_set(
baton->buffer,baton->data,baton->datalen    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBuf::SetWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->buffer) {
    to = Nan::New<String>(baton->buffer->ptr, baton->buffer->size).ToLocalChecked();
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
      workerArguments.push(GetFromPersistent("data"));
      workerArguments.push(GetFromPersistent("datalen"));
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
        Local<v8::Object> err = Nan::Error("Method set has thrown an error.")->ToObject();
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

  git_buf_free(baton->buffer);
  free((void *)baton->buffer);

  delete baton;
}

       NAN_METHOD(GitBuf::Ptr) {
      Local<v8::Value> to;

       char *
         ptr =
         Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()->ptr;
 // start convert_to_v8 block
  if (ptr){
       to = Nan::New<String>(ptr).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBuf::Asize) {
      Local<v8::Value> to;

       size_t
         asize =
         Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()->asize;
 // start convert_to_v8 block
     to = Nan::New<Number>( asize);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBuf::Size) {
      Local<v8::Value> to;

       size_t
         size =
         Nan::ObjectWrap::Unwrap<GitBuf>(info.This())->GetValue()->size;
 // start convert_to_v8 block
     to = Nan::New<Number>( size);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitBuf::constructor_template;
 