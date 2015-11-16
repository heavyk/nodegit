// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cred.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCred::GitCred(git_cred *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCred::~GitCred() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                    }

  void GitCred::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Cred").ToLocalChecked());

           Nan::SetMethod(tpl, "defaultNew", DefaultNew);
            Nan::SetPrototypeMethod(tpl, "hasUsername", HasUsername);
             Nan::SetMethod(tpl, "sshKeyFromAgent", SshKeyFromAgent);
             Nan::SetMethod(tpl, "sshKeyMemoryNew", SshKeyMemoryNew);
             Nan::SetMethod(tpl, "sshKeyNew", SshKeyNew);
             Nan::SetMethod(tpl, "usernameNew", UsernameNew);
             Nan::SetMethod(tpl, "userpassPlaintextNew", UserpassPlaintextNew);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Cred").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCred::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCred cannot be instantiated.");
     }

    GitCred* object = new GitCred(static_cast<git_cred *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCred::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCred::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cred *GitCred::GetValue() {
    return this->raw;
  }

  git_cred **GitCred::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCred::ClearValue() {
    this->raw = NULL;
  }

  
/*
    * @return Cred out    */
NAN_METHOD(GitCred::DefaultNew) {
  Nan::EscapableHandleScope scope;

  git_cred * out = 0;
 git_cred_default_new(
&out
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitCred::HasUsername) {
  Nan::EscapableHandleScope scope;

   int result = git_cred_has_username(
Nan::ObjectWrap::Unwrap<GitCred>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param String username
     * @return Cred out    */
NAN_METHOD(GitCred::SshKeyFromAgent) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username;

  String::Utf8Value username(info[0]->ToString());
  from_username = (const char *) strdup(*username);
// end convert_from_v8 block
 git_cred_ssh_key_from_agent(
&out
,from_username
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param String username
   * @param String publickey
   * @param String privatekey
   * @param String passphrase
    * @param Cred callback
   */
NAN_METHOD(GitCred::SshKeyMemoryNew) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String publickey is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String privatekey is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String passphrase is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SshKeyMemoryNewBaton* baton = new SshKeyMemoryNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_username;

  String::Utf8Value username(info[0]->ToString());
  from_username = (const char *) strdup(*username);
// end convert_from_v8 block
  baton->username = from_username;
// start convert_from_v8 block
  const char * from_publickey;

  String::Utf8Value publickey(info[1]->ToString());
  from_publickey = (const char *) strdup(*publickey);
// end convert_from_v8 block
  baton->publickey = from_publickey;
// start convert_from_v8 block
  const char * from_privatekey;

  String::Utf8Value privatekey(info[2]->ToString());
  from_privatekey = (const char *) strdup(*privatekey);
// end convert_from_v8 block
  baton->privatekey = from_privatekey;
// start convert_from_v8 block
  const char * from_passphrase;

  String::Utf8Value passphrase(info[3]->ToString());
  from_passphrase = (const char *) strdup(*passphrase);
// end convert_from_v8 block
  baton->passphrase = from_passphrase;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  SshKeyMemoryNewWorker *worker = new SshKeyMemoryNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("username", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("publickey", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("privatekey", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("passphrase", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCred::SshKeyMemoryNewWorker::Execute() {
  int result = git_cred_ssh_key_memory_new(
&baton->out,baton->username,baton->publickey,baton->privatekey,baton->passphrase    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCred::SshKeyMemoryNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitCred baton->out
       to = GitCred::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("username"));
      workerArguments.push(GetFromPersistent("publickey"));
      workerArguments.push(GetFromPersistent("privatekey"));
      workerArguments.push(GetFromPersistent("passphrase"));
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
        Local<v8::Object> err = Nan::Error("Method sshKeyMemoryNew has thrown an error.")->ToObject();
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

  free((void *)baton->username);
  free((void *)baton->publickey);
  free((void *)baton->privatekey);
  free((void *)baton->passphrase);

  delete baton;
}

   
/*
  * @param String username
   * @param String publickey
   * @param String privatekey
   * @param String passphrase
     * @return Cred out    */
NAN_METHOD(GitCred::SshKeyNew) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String publickey is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String privatekey is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String passphrase is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username;

  String::Utf8Value username(info[0]->ToString());
  from_username = (const char *) strdup(*username);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_publickey;

  String::Utf8Value publickey(info[1]->ToString());
  from_publickey = (const char *) strdup(*publickey);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_privatekey;

  String::Utf8Value privatekey(info[2]->ToString());
  from_privatekey = (const char *) strdup(*privatekey);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_passphrase;

  String::Utf8Value passphrase(info[3]->ToString());
  from_passphrase = (const char *) strdup(*passphrase);
// end convert_from_v8 block
 git_cred_ssh_key_new(
&out
,from_username
,from_publickey
,from_privatekey
,from_passphrase
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param String username
    * @param Cred callback
   */
NAN_METHOD(GitCred::UsernameNew) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  UsernameNewBaton* baton = new UsernameNewBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_username;

  String::Utf8Value username(info[0]->ToString());
  from_username = (const char *) strdup(*username);
// end convert_from_v8 block
  baton->username = from_username;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  UsernameNewWorker *worker = new UsernameNewWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("username", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCred::UsernameNewWorker::Execute() {
  int result = git_cred_username_new(
&baton->cred,baton->username    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCred::UsernameNewWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->cred != NULL) {
    // GitCred baton->cred
       to = GitCred::New((void *)baton->cred, false);
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
      workerArguments.push(GetFromPersistent("username"));
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
        Local<v8::Object> err = Nan::Error("Method usernameNew has thrown an error.")->ToObject();
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

  free((void *)baton->username);

  delete baton;
}

   
/*
  * @param String username
   * @param String password
     * @return Cred out    */
NAN_METHOD(GitCred::UserpassPlaintextNew) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String username is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String password is required.");
  }

  git_cred * out = 0;
// start convert_from_v8 block
  const char * from_username;

  String::Utf8Value username(info[0]->ToString());
  from_username = (const char *) strdup(*username);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_password;

  String::Utf8Value password(info[1]->ToString());
  from_password = (const char *) strdup(*password);
// end convert_from_v8 block
 git_cred_userpass_plaintext_new(
&out
,from_username
,from_password
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitCred out
       to = GitCred::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitCred::constructor_template;
 