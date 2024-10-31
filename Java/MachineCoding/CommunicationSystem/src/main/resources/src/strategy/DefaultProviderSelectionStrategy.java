package strategy;

import domain.Provider;

import java.util.List;
public class DefaultProviderSelectionStrategy implements ProviderSelectionStrategyInterface {

    @Override
    public Provider selectProvider(List<Provider> providers) {
        int randomNumber = (int) (Math.random() * providers.size());
        return providers.get(randomNumber);
    }
}
