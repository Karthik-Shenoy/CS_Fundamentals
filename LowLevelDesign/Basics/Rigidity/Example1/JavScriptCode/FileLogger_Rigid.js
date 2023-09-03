var Product = /** @class */ (function () {
    function Product(name) {
        this._name = "";
        if (name != "")
            this._name = name;
    }
    Object.defineProperty(Product.prototype, "name", {
        get: function () {
            return this._name;
        },
        enumerable: false,
        configurable: true
    });
    return Product;
}());
var ProductStore = /** @class */ (function () {
    function ProductStore() {
        this._productList = [];
        this._logger = new FileLogger();
    }
    ProductStore.prototype.addProduct = function (product) {
        this._productList.push(product);
        this._logger.addTrace("ProductStore: added product (".concat(product.name, ") to the prodcut store"));
    };
    ProductStore.prototype.removeProduct = function (purchasedProduct) {
        var productIndex = 0;
        for (var idx = 0; idx < this._productList.length; idx++) {
            if (this._productList[idx] === purchasedProduct) {
                productIndex = idx;
                break;
            }
        }
        // delete operation on array
        for (var idx = productIndex; idx < this._productList.length - 1; idx++) {
            this._productList[idx] = this._productList[idx + 1];
        }
        this._productList.pop();
        this._logger.addTrace("ProductStore: removed product (".concat(purchasedProduct.name, ") to the prodcut store"));
    };
    ProductStore.prototype.isProductPresent = function (prodcut) {
        return this._productList.indexOf(prodcut) !== -1;
    };
    return ProductStore;
}());
var User = /** @class */ (function () {
    function User() {
        this._userId = 0;
        this._logger = new FileLogger();
        this._userId = Date.now() % 100000;
        this._logger.addTrace("User (".concat(this._userId, ") created"));
    }
    User.prototype.purchaseProduct = function (product, productStore) {
        if (productStore.isProductPresent(product)) {
            this._logger.addTrace("User (".concat(this._userId, ") purchased the product (").concat(product.name, ")"));
            productStore.removeProduct(product);
        }
        else {
            this._logger.addTrace("The requeseted Product has already been purchased.");
        }
    };
    return User;
}());
var FileLogger = /** @class */ (function () {
    function FileLogger() {
    }
    FileLogger.prototype.addTrace = function (traceString) {
        console.log("added the following log to the file : ", traceString);
    };
    return FileLogger;
}());
var user1 = new User();
var user2 = new User();
var product1 = new Product("milk");
var product2 = new Product("Bread");
var product3 = new Product("milk"); // same prduct but diff ID
var productStore = new ProductStore();
console.log("\n");
productStore.addProduct(product1);
productStore.addProduct(product2);
productStore.addProduct(product3);
console.log("\n");
user1.purchaseProduct(product1, productStore);
user1.purchaseProduct(product1, productStore); // cant purchase as the product is already gone
user1.purchaseProduct(product2, productStore);
