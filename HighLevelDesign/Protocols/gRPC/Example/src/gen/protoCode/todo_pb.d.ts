// package: todoPackage
// file: todo.proto

/* tslint:disable */
/* eslint-disable */

import * as jspb from "google-protobuf";

export class voidMessage extends jspb.Message { 

    serializeBinary(): Uint8Array;
    toObject(includeInstance?: boolean): voidMessage.AsObject;
    static toObject(includeInstance: boolean, msg: voidMessage): voidMessage.AsObject;
    static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
    static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
    static serializeBinaryToWriter(message: voidMessage, writer: jspb.BinaryWriter): void;
    static deserializeBinary(bytes: Uint8Array): voidMessage;
    static deserializeBinaryFromReader(message: voidMessage, reader: jspb.BinaryReader): voidMessage;
}

export namespace voidMessage {
    export type AsObject = {
    }
}

export class TodoItem extends jspb.Message { 
    getId(): number;
    setId(value: number): TodoItem;
    getText(): string;
    setText(value: string): TodoItem;

    serializeBinary(): Uint8Array;
    toObject(includeInstance?: boolean): TodoItem.AsObject;
    static toObject(includeInstance: boolean, msg: TodoItem): TodoItem.AsObject;
    static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
    static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
    static serializeBinaryToWriter(message: TodoItem, writer: jspb.BinaryWriter): void;
    static deserializeBinary(bytes: Uint8Array): TodoItem;
    static deserializeBinaryFromReader(message: TodoItem, reader: jspb.BinaryReader): TodoItem;
}

export namespace TodoItem {
    export type AsObject = {
        id: number,
        text: string,
    }
}

export class TodoItems extends jspb.Message { 
    clearItemsList(): void;
    getItemsList(): Array<TodoItem>;
    setItemsList(value: Array<TodoItem>): TodoItems;
    addItems(value?: TodoItem, index?: number): TodoItem;

    serializeBinary(): Uint8Array;
    toObject(includeInstance?: boolean): TodoItems.AsObject;
    static toObject(includeInstance: boolean, msg: TodoItems): TodoItems.AsObject;
    static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
    static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
    static serializeBinaryToWriter(message: TodoItems, writer: jspb.BinaryWriter): void;
    static deserializeBinary(bytes: Uint8Array): TodoItems;
    static deserializeBinaryFromReader(message: TodoItems, reader: jspb.BinaryReader): TodoItems;
}

export namespace TodoItems {
    export type AsObject = {
        itemsList: Array<TodoItem.AsObject>,
    }
}
