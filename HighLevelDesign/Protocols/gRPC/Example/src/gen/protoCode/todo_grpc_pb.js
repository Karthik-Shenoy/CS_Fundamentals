// GENERATED CODE -- DO NOT EDIT!

'use strict';
var grpc = require('@grpc/grpc-js');
var todo_pb = require('./todo_pb.js');

function serialize_todoPackage_TodoItem(arg) {
  if (!(arg instanceof todo_pb.TodoItem)) {
    throw new Error('Expected argument of type todoPackage.TodoItem');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_todoPackage_TodoItem(buffer_arg) {
  return todo_pb.TodoItem.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_todoPackage_voidMessage(arg) {
  if (!(arg instanceof todo_pb.voidMessage)) {
    throw new Error('Expected argument of type todoPackage.voidMessage');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_todoPackage_voidMessage(buffer_arg) {
  return todo_pb.voidMessage.deserializeBinary(new Uint8Array(buffer_arg));
}


var TodoService = exports.TodoService = {
  createTodo: {
    path: '/todoPackage.Todo/createTodo',
    requestStream: false,
    responseStream: false,
    requestType: todo_pb.TodoItem,
    responseType: todo_pb.TodoItem,
    requestSerialize: serialize_todoPackage_TodoItem,
    requestDeserialize: deserialize_todoPackage_TodoItem,
    responseSerialize: serialize_todoPackage_TodoItem,
    responseDeserialize: deserialize_todoPackage_TodoItem,
  },
  readTodo: {
    path: '/todoPackage.Todo/readTodo',
    requestStream: false,
    responseStream: false,
    requestType: todo_pb.voidMessage,
    responseType: todo_pb.TodoItem,
    requestSerialize: serialize_todoPackage_voidMessage,
    requestDeserialize: deserialize_todoPackage_voidMessage,
    responseSerialize: serialize_todoPackage_TodoItem,
    responseDeserialize: deserialize_todoPackage_TodoItem,
  },
  readTodos: {
    path: '/todoPackage.Todo/readTodos',
    requestStream: false,
    responseStream: true,
    requestType: todo_pb.voidMessage,
    responseType: todo_pb.TodoItem,
    requestSerialize: serialize_todoPackage_voidMessage,
    requestDeserialize: deserialize_todoPackage_voidMessage,
    responseSerialize: serialize_todoPackage_TodoItem,
    responseDeserialize: deserialize_todoPackage_TodoItem,
  },
};

exports.TodoClient = grpc.makeGenericClientConstructor(TodoService);
