// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/transport.h>
 }

#include "../include/functions/copy.h"
#include "../include/transport.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/remote.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTransport::GitTransport(git_transport *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTransport::~GitTransport() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
               }

  void GitTransport::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Transport").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "init", Init);
             Nan::SetMethod(tpl, "sshWithPaths", SshWithPaths);
             Nan::SetMethod(tpl, "unregister", Unregister);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Transport").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTransport::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTransport cannot be instantiated.");
     }

    GitTransport* object = new GitTransport(static_cast<git_transport *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTransport::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTransport::constructor_template), 2, argv).ToLocalChecked());
  }

  git_transport *GitTransport::GetValue() {
    return this->raw;
  }

  git_transport **GitTransport::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTransport::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitTransport::Init) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_transport_init(
Nan::ObjectWrap::Unwrap<GitTransport>(info.This())->GetValue()
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Remote owner
   * @param Void payload
    * @param Transport callback
   */
NAN_METHOD(GitTransport::SshWithPaths) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Remote owner is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SshWithPathsBaton* baton = new SshWithPathsBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  SshWithPaths_globalPayload* globalPayload = new SshWithPaths_globalPayload;
// start convert_from_v8 block
  git_remote * from_owner;
  from_owner = Nan::ObjectWrap::Unwrap<GitRemote>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->owner = from_owner;
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  SshWithPathsWorker *worker = new SshWithPathsWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("owner", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("payload", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTransport::SshWithPathsWorker::Execute() {
  int result = git_transport_ssh_with_paths(
&baton->out,baton->owner,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTransport::SshWithPathsWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTransport baton->out
       to = GitTransport::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("owner"));
      workerArguments.push(GetFromPersistent("payload"));
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
        Local<v8::Object> err = Nan::Error("Method sshWithPaths has thrown an error.")->ToObject();
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

  delete (SshWithPaths_globalPayload*)baton->payload;

  delete baton;
}

   
/*
 * @param String prefix
     * @return Number  result    */
NAN_METHOD(GitTransport::Unregister) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String prefix is required.");
  }

// start convert_from_v8 block
  const char * from_prefix;

  String::Utf8Value prefix(info[0]->ToString());
  from_prefix = (const char *) strdup(*prefix);
// end convert_from_v8 block
   int result = git_transport_unregister(
from_prefix
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitTransport::constructor_template;
 