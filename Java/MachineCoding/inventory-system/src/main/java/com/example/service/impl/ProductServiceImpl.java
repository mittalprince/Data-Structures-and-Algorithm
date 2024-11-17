package com.example.service.impl;

import com.example.entity.Product;
import com.example.repository.InMemoryProductRepository;
import com.example.repository.ProductRepository;
import com.example.service.ProductService;

import java.util.List;

public class ProductServiceImpl implements ProductService {
    private final ProductRepository productRepository;

    public ProductServiceImpl(ProductRepository productRepository){
        this.productRepository = productRepository;
    }
    public void addProduct(Product product) {
        productRepository.addProduct(product);
    }
    public void removeProduct(String productId) throws Exception {
        Product product = productRepository.getProductById(productId);
        if (product == null) {
            throw new Exception("Product with ID " + productId + " not found.");
        }
        int quantity = product.getQuantity();
        if (quantity <= 0) {
            throw new Exception("Product with ID " + productId + " is out of stock.");
        }
        product.setQuantity(quantity - 1);
    }

    @Override
    public List<Product> getAllProducts() {
        return productRepository.getAllProducts();
    }
}
