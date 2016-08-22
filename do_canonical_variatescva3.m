function do_canonical_variatescva3

% Function implementing the Canonical Variates Analysis method
% written by Prof Geoff Bohling - March 2006
% from the University of Kansas, US

% Modified by Dr William Sellers, University of Manchester, UK to produce various color images

% Modified to read Class text files produced by ImageJ version 1.49v and
% a set of multispectral images

% 

F1 = dir('*.tif');

strname = F1(1,1).name;
new_claim = strrep(strname,'.tif','');


F = dir('class*.txt');
s1 = size(F,1);


for i=1:s1
    
   bin_names{i} = F(i).name;
    
end


for i=1:s1
    fid(i,1) = fopen(F(i,1).name,'r');
    tline = fgetl(fid(i,1));
    
    
    C{i,1} =textscan(fid(i,1), '%d %f %d %d %d %d %d');
    
   
end


X(:,1) = C{1,1}(1,6);

Y(:,1) = C{1,1}(1,7);

for i=2:s1
    X = [X;C{i,1}(1,6)];
end



for i=2:s1
    Y = [Y;C{i,1}(1,7)];
end


index=0;
for i =1:size(Y,1)
   for j =1:size(Y{i,1},1)
      index = index+1;
      YY(index,1) = Y{i,1}(j,1); 
   end    
end    
Y=YY;

index=0;
for i =1:size(X,1)
   for j =1:size(X{i,1},1)
      index = index+1;
      XX(index,1) = X{i,1}(j,1); 
   end    
end    
X=XX;


for i=1:s1
    
   fclose(fid(i,1));
end

prst=C{1,1}(1,7);

N= size(prst{1,1},1);

for i=2:s1
   prst=C{i,1}(1,7);    
   N=N+size(prst{1,1},1); 
end

index=0;
for j=1:s1
  prst=C{j,1}(1,7);    
  bin_letters(j,1) =sprintf('%d',j);
  for i=1:size(prst{1,1},1)
      index = index +1;
      Class1(index,1) = sprintf('%d',j);
      %bin_letters(index) = sprintf('%d',j);
  end
end
 


n_images = length(F1);




n_samples  = size(X,1);

data_matrix = zeros(n_samples, n_images);
grouping_vector = zeros(n_samples, 1);

image_list = {};


for i_image = 1: n_images
    indices(i_image) = i_image;
    
   
    file_path = fullfile(F1(i_image).name);
    
        
    fprintf('Reading %s\n', file_path);
  
    data1 = imread(file_path);%reads a grayscale or a colour photo
    
    if size(data1,2) > 1
        data = data1(:,:,1);
    else
        data = data1;
    end    
        
  
    if i_image == 1
        [height, width] = size(data);
       
        image_list = zeros(height, width, n_images, 'uint8');
    end
   
    
    image_list(:, :, i_image) = data;
    
    for i_sample = 1: n_samples
        index = match_string(bin_letters, Class1(i_sample));
       
        
        if index > 0
            grouping_vector(i_sample) = index;
       
    
        end
    end
  
end
tic

[coef,score,ev,S,B] = canonize(data_matrix, grouping_vector);


size(S);
size(B);
size(ev);

new_image_cv1 = zeros(height, width);
new_image_cv2 = zeros(height, width);
new_image_cv3 = zeros(height, width);

new_image_cv4 = zeros(height, width);

image_list_cols = reshape(image_list, [width*height, n_images]); % this puts the data for each image data into a single column


image_list_cols(1:100)


new_image_cv1 = double(image_list_cols) * double(coef(:, 1));
new_image_cv2 = double(image_list_cols) * double(coef(:, 2));
new_image_cv3 = double(image_list_cols) * double(coef(:, 3));
new_image_cv1 = reshape(new_image_cv1, [height, width]);
new_image_cv2 = reshape(new_image_cv2, [height, width]);
new_image_cv3 = reshape(new_image_cv3, [height, width]);%h   - 7216



range_cv1 = range_map(new_image_cv1, min(min(new_image_cv1)), max(max(new_image_cv1)), 0, 255, 0, 255);
range_cv2 = range_map(new_image_cv2, min(min(new_image_cv2)), max(max(new_image_cv2)), 0, 255, 0, 255);
range_cv3 = range_map(new_image_cv3, min(min(new_image_cv3)), max(max(new_image_cv3)), 0, 255, 0, 255);

range_cv4 = range_map(new_image_cv4, min(min(new_image_cv4)), max(max(new_image_cv4)), 0, 255, 0, 255);


new_image_colour = zeros(height, width, 3, 'uint8');



new_image_colour(:,:,1) = uint8(range_cv1);
new_image_colour(:,:,2) = uint8(range_cv2);
new_image_colour(:,:,3) = uint8(range_cv3); 

imwrite(new_image_colour(:,:,:), strcat(new_claim,'image_rangecva.tif'), 'tiff', 'compression', 'lzw');


score_cv1 = range_map(new_image_cv1, min(score(:,1)), max(score(:,1)), 0, 255, 0, 255);
score_cv2 = range_map(new_image_cv2, min(score(:,2)), max(score(:,2)), 0, 255, 0, 255);
score_cv3 = range_map(new_image_cv3, min(score(:,3)), max(score(:,3)), 0, 255, 0, 255);

new_image_colour(:,:,1) = uint8(score_cv1);
new_image_colour(:,:,2) = uint8(score_cv2);
new_image_colour(:,:,3) = uint8(score_cv3); 

imwrite(new_image_colour(:,:,:), strcat(new_claim,'image_score_rangecva.tif'), 'tiff', 'compression', 'lzw');

required_percentiles = [0.01, 0.1, 1, 5, 99.99, 99.9, 99, 95];
n_percentiles = length(required_percentiles) / 2;
percentiles_cv1 = Percentile(new_image_cv1, required_percentiles);
percentiles_cv2 = Percentile(new_image_cv2, required_percentiles);
percentiles_cv3 = Percentile(new_image_cv3, required_percentiles);
for i = 1: n_percentiles
    fprintf('Processing percentile %f\n', required_percentiles(i));
    
    per_cv1 = range_map(new_image_cv1, percentiles_cv1(i), percentiles_cv1(i + n_percentiles), 0, 255, 0, 255);
    per_cv2 = range_map(new_image_cv2, percentiles_cv2(i), percentiles_cv2(i + n_percentiles), 0, 255, 0, 255);
    per_cv3 = range_map(new_image_cv3, percentiles_cv3(i), percentiles_cv3(i + n_percentiles), 0, 255, 0, 255);
    
    new_image_colour(:,:,1) = uint8(per_cv1);
    new_image_colour(:,:,2) = uint8(per_cv2);
    new_image_colour(:,:,3) = uint8(per_cv3);
    
    imwrite(new_image_colour(:,:,:), strcat(new_claim,sprintf('image_percentile_%0.2fcva.tif', required_percentiles(i))), 'tiff', 'compression', 'lzw');
end
toc 




function [coef,score,ev,S,B] = canonize(X,grp)
% Performs canonical variate matrix of data in X.
% gcb, 04 March 2006
% X: N x D data matrix, data points in rows, variables in columns
% grp: grouping vector, containing integers between 1 and K
%         where K is the number of groups
% coef: coefficients for forming canonical variates
%         (eigenvectors of inv(S)*B)
% score: canonical variate scores
% S: within-groups covariance matrix
% B: between-groups covariance matrix

%size(X) - 200 23
%size(grp) - 200 1

%X = [1 4 2;5 7 8;20 12 10;5 12 4;15 5 9;3 8 9;13 2 7;3 9 8;3 9 8];
%grp =[1;1;1;2;2;2;3;3; 3];
%X
%ee

N = size(X,1);  % number of data (rows)
D = size(X,2);  % number of variables (columns)
K = max(grp);   % number of groups

xmg = mean(X);  % global mean vector (1 x D)

xmk = zeros(K,D);  % will hold group means
nk = zeros(K,1);   % number of data per group
for k = 1:K
    X(grp==k,:);
    xmk(k,:) = mean(X(grp==k,:));
    nk(k) = size(X(grp==k,:),1);
end
% calc within-groups cov. mat.
S = zeros(D,D);
for i = 1:N
    % get diff from appropriate group mean, as row vector
    xdiff = X(i,:) - xmk(grp(i),:);
    xdiff'*xdiff;
    S = S + xdiff'*xdiff;
end
S;
S = S/(N-K);
S;
% calc between-groups cov. mat.
B = zeros(D,D);

for k = 1:K
   
    B = B + nk(k)*(xmk(k,:)-xmg)'*(xmk(k,:)-xmg);
   
end
B = ((K/(K-1)).*B)./N;
[coef,ev] = eig(B,S);

[ev,iev] = sort(diag(ev),1,'descend');

coef = coef(:,iev);
X;
size(coef);
% compute matrix of scores

score = X*coef;
X;
return

% this function returns the index of the matching element in a list
% it returns 0 on error
function index = match_string(list, target)

for i = 1: length(list)
    if strcmp(list(i), target)
        index = i;
        return
    end
end
index = 0;
return

% this function reads data from a whitespace delimited ascii file
% and creates a map object with the colum headings as keys

function [output_map] = read_named_columns_as_map(file_name)

[names, data] = read_named_columns(file_name);

output_map = containers.Map();
for i = 1: length(names)
    tf = isKey(output_map, names{i});
    if tf ~= 0
        fprintf('Duplicate column heading: %s\n', names{i})
    end
    output_map(names{i}) = data{i};
end

return

% this function reads data from a whitespace delimited ascii file
% with colum headings
% it tries to work out whether the columns contain numbers or text
function [names, data] = read_named_columns(file_name)

fprintf('Reading "%s"\n', file_name);
% read the data
[fid, message] = fopen(file_name);
if (fid == -1)
   error(message);
end
header_line = fgetl(fid); % reads line without end of line character
data_start_position = ftell(fid);
names = regexp(header_line, '\S*', 'match');

% now try parsing the first data line
test_line = fgetl(fid);
test_data = regexp(test_line, '\S*', 'match');
format_str = '';
all_numbers = 1;
num_cols = length(test_data);


for i = 1: num_cols
   match = regexp(test_data{i}, '^([+-]?)(?=\d|\.\d)\d*(\.\d*)?([Ee]([+-]?\d+))?$', 'match');
   if isempty(match)
       format_str = [format_str '%s'];
       all_numbers = 0;
   else
       format_str = [format_str '%f'];
   end
end

% now read the data in the file for real
fseek(fid, data_start_position, 'bof');
if all_numbers == 0
   data = textscan(fid, format_str);
else
   raw_data = fread(fid,'uint8=>char');
   data_array = reshape(sscanf(raw_data, format_str), num_cols, []);
   data = {};
   for i = 1: num_cols
       data{i} = data_array(i, :)';
   end
end

fclose(fid);

return

% function to produce a scatter plot identified by symbol and colour
function two_group_scatter(x, y, symbol_group, colour_group, symbols, colours)

scatter(x,y,'Marker','none');
for i = 1: length(x)
    
    text(x(i), y(i), symbols(symbol_group(i)), 'Color', colours(colour_group(i)), 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
    
end

% function to produce a scatter plot identified by symbol
function one_group_scatter(x, y, symbol_group, symbols)

scatter(x,y,'Marker','none');
for i = 1: length(x)
    
    text(x(i), y(i), symbols(symbol_group(i)), 'Color', 'k', 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
    
end

% function to produce a 3d scatter plot identified by colour
% colour_group can contain numbers or letters
function one_group_3d_scatter(x, y, z, colour_group, markers, colours)

x_data_map = containers.Map();
y_data_map = containers.Map();
z_data_map = containers.Map();

for i = 1: length(colour_group)
    tf = isKey(x_data_map, colour_group{i});
    if tf ~= 0
        data = x_data_map(colour_group{i});
        data(end + 1) = x(i);
        x_data_map(colour_group{i}) = data;
        data = y_data_map(colour_group{i});
        data(end + 1) = y(i);
        y_data_map(colour_group{i}) = data;
        data = z_data_map(colour_group{i});
        data(end + 1) = z(i);
        z_data_map(colour_group{i}) = data;
    else
        x_data_map(colour_group{i}) = [x(i)];
        y_data_map(colour_group{i}) = [y(i)];
        z_data_map(colour_group{i}) = [z(i)];
    end
end

allKeys = keys(x_data_map);
hold on;
for i = 1: length(allKeys)
    plot3(x_data_map(allKeys{i}), y_data_map(allKeys{i}), z_data_map(allKeys{i}), 'LineStyle', 'none', 'Marker', markers{i}, 'color', colours{i});
end

return

% this function maps the dynamic range of an image from one range to another
function out_image = range_map(in_image, in_low, in_high, out_low, out_high, out_range_low, out_range_high)

out_image = in_image;
[ny, nx] = size(in_image);

for ix = 1: nx
    for iy = 1: ny
        v = double(in_image(iy, ix));
        if v < in_low
            v2 = out_range_low;
        else
            if v > in_high
                v2 = out_range_high;
            else
                v2 = ((v - in_low) / (in_high - in_low)) * (out_high - out_low) + out_low;
            end
        end
        out_image(iy, ix) = uint8(floor(v2 + 0.5));
    end
end

return

% calculate the percentiles of a list of values
function percentile_values = Percentile(arr, percentiles)

vals = sort(reshape(arr, 1, []));
percentile_values = percentiles;
for i = 1: length(percentiles)
    index = round(1 + (percentiles(i)/100) * (length(vals) - 1));
    percentile_values(i) = vals(index);
end

return

% function to convert a list of numbers to an equivalent list of strings
function names = num2stringlist(numbers)

names = cell(length(numbers), 1);
for i = 1: length(numbers)
    names{i} = num2str(numbers(i));
end

return

