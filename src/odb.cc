// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/odb.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/odb_object.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitOdb::GitOdb(git_odb *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitOdb::~GitOdb() {
      if (this->selfFreeing) {
        git_odb_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                          }

  void GitOdb::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Odb").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "addDiskAlternate", AddDiskAlternate);
            Nan::SetPrototypeMethod(tpl, "free", Free);
             Nan::SetMethod(tpl, "open", Open);
            Nan::SetPrototypeMethod(tpl, "read", Read);
            Nan::SetPrototypeMethod(tpl, "write", Write);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Odb").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitOdb::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitOdb cannot be instantiated.");
     }

    GitOdb* object = new GitOdb(static_cast<git_odb *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitOdb::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitOdb::constructor_template), 2, argv).ToLocalChecked());
  }

  git_odb *GitOdb::GetValue() {
    return this->raw;
  }

  git_odb **GitOdb::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitOdb::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitOdb::AddDiskAlternate) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_odb_add_disk_alternate(
Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->GetValue()
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitOdb::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->GetValue() != NULL) {
 git_odb_free(
Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
  * @param String objects_dir
    * @param Odb callback
   */
NAN_METHOD(GitOdb::Open) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String objects_dir is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBaton* baton = new OpenBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_objects_dir;

  String::Utf8Value objects_dir(info[0]->ToString());
  from_objects_dir = (const char *) strdup(*objects_dir);
// end convert_from_v8 block
  baton->objects_dir = from_objects_dir;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  OpenWorker *worker = new OpenWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("objects_dir", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitOdb::OpenWorker::Execute() {
  int result = git_odb_open(
&baton->out,baton->objects_dir    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitOdb::OpenWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOdb baton->out
       to = GitOdb::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("objects_dir"));
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
        Local<v8::Object> err = Nan::Error("Method open has thrown an error.")->ToObject();
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

  free((void *)baton->objects_dir);

  delete baton;
}

  
/*
    * @param Oid id
    * @param OdbObject callback
   */
NAN_METHOD(GitOdb::Read) {

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ReadBaton* baton = new ReadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->db = Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->GetValue();
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[0]->IsString();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  ReadWorker *worker = new ReadWorker(baton, callback);
  worker->SaveToPersistent("db", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("id", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitOdb::ReadWorker::Execute() {
  int result = git_odb_read(
&baton->out,baton->db,baton->id    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitOdb::ReadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOdbObject baton->out
       to = GitOdbObject::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("id"));
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
        Local<v8::Object> err = Nan::Error("Method read has thrown an error.")->ToObject();
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
    * @param Buffer data
   * @param Number len
   * @param Number type
    * @param Oid callback
   */
NAN_METHOD(GitOdb::Write) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("Buffer data is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number type is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  WriteBaton* baton = new WriteBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->out = (git_oid *)malloc(sizeof(git_oid ));
  baton->odb = Nan::ObjectWrap::Unwrap<GitOdb>(info.This())->GetValue();
// start convert_from_v8 block
  const void * from_data;

  String::Utf8Value data(info[0]->ToString());
  from_data = (const void *) strdup(*data);
// end convert_from_v8 block
  baton->data = from_data;
// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->len = from_len;
// start convert_from_v8 block
  git_otype from_type;
  from_type = (git_otype)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->type = from_type;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  WriteWorker *worker = new WriteWorker(baton, callback);
  worker->SaveToPersistent("odb", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("data", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("len", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("type", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitOdb::WriteWorker::Execute() {
  int result = git_odb_write(
baton->out,baton->odb,baton->data,baton->len,baton->type    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitOdb::WriteWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOid baton->out
       to = GitOid::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("len"));
      workerArguments.push(GetFromPersistent("type"));
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
        Local<v8::Object> err = Nan::Error("Method write has thrown an error.")->ToObject();
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

      Nan::Persistent<Function> GitOdb::constructor_template;
 