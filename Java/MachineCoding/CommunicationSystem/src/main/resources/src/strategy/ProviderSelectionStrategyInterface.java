package strategy;

import domain.Provider;

import java.util.List;

public interface ProviderSelectionStrategyInterface {
    Provider selectProvider(List<Provider> providers);
}
