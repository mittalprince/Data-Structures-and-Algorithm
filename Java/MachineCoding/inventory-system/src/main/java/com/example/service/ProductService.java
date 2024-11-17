package com.example.service;

import com.example.entity.Product;

import java.util.List;

public interface ProductService {
    void addProduct(Product product);
    void removeProduct(String productId) throws Exception;
    List<Product> getAllProducts();
}
