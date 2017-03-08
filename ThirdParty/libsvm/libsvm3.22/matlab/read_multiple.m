function [labels, instances] = read_multiple(files)
    labels = [];
    instances = [];
    iter = 0;
    
    for file = files
        [l, i] = libsvmread(file{1});
        if iter == 0
            %labels = l;
            labels = (iter + 1) * ones(size(l, 1), 1);
            instances = i;
        else
            %labels = [labels; l];
            labels = [labels; (iter + 1) * ones(size(l, 1), 1)];
            instances = [instances; i];
        end
        iter = iter + 1;
    end
end