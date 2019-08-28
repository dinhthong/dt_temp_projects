window.Bizweb || (window.Bizweb = {});

Bizweb.mediaDomainName = "//bizweb.dktcdn.net/";

// ---------------------------------------------------------------------------------
// Bizweb Js - Public Static Functions
// ---------------------------------------------------------------------------------
Bizweb.each = function (array, callback) {
    for (var i = 0; i < array.length; i++) {
        callback(array[i], i);
    }
};
Bizweb.getClass = function (obj) {
    return Object.prototype.toString.call(obj).slice(8, -1);
};
Bizweb.map = function (array, callback) {
    var result = [];

    for (var i = 0; i < array.length; i++) {
        result.push(callback(array[i], i));
    }

    return result;
};
Bizweb.arrayContains = function (array, obj) {
    for (var i = 0; i < array.length; i++) {
        if (array[i] == obj)
            return true;
    }

    return false;
};
Bizweb.distinct = function (array) {
    var result = [];

    for (var i = 0; i < array.length; i++) {
        if (!Bizweb.arrayContains(result, array[i]))
            result.push(array[i]);
    }

    return result;
};
Bizweb.getUrlParameter = function (name) {
    var match = RegExp('[?&]' + name + '=([^&]*)').exec(window.location.search);
    return match && decodeURIComponent(match[1].replace(/\+/g, ' '));
}
Bizweb.uniq = function (array) {
    var result = [];

    for (var i = 0; i < array.length; i++) {
        if (!Bizweb.arrayIncludes(result, array[i]))
            result.push(array[i]);
    }

    return result;
}
Bizweb.arrayIncludes = function (array, target) {
    for (var i = 0; i < array.length; i++) {
        if (array[i] == target)
            return true;
    }

    return false;
}

// ---------------------------------------------------------------------------------
// Bizweb Js - Product
//
// Working with Product object
// ---------------------------------------------------------------------------------
Bizweb.Product = function () {
    function Product(data) {
        if (typeof data != 'undefined') {
            for (property in data) {
                this[property] = data[property];
            }
        }
    };

    // BEGIN: ThemeEditor - Public Functions
    Product.prototype.optionNames = function () {
        if (Bizweb.getClass(this.options) == 'Array')
            return this.options;
        else
            return [];
    };
    Product.prototype.optionValues = function (index) {
        if (typeof this.variants == 'undefined')
            return null;

        var results = Bizweb.map(this.variants, function (e) {
            var option_col = "option" + (index + 1);
            if (typeof e[option_col] == 'undefined')
                return null;
            else
                return e[option_col];
        });

        if (results[0] == null)
            return null;
        else
            return Bizweb.distinct(results);
    };
    Product.prototype.getVariant = function (selectedValues) {
        var found = null;

        if (selectedValues.length != this.options.length)
            return null;

        Bizweb.each(this.variants, function (variant) {
            var isSatisfied = true;

            for (var j = 0; j < selectedValues.length; j++) {
                var option_col = "option" + (j + 1);
                if (variant[option_col] != selectedValues[j]) {
                    isSatisfied = false;
                }
            }

            if (isSatisfied) {
                found = variant;
                return;
            }
        });

        return found;
    };
    Product.prototype.getVariantById = function (id) {
        for (var i = 0; i < this.variants.length; i++) {
            var variant = this.variants[i];
            if (variant.id == id)
                return variant;
        }

        return null;
    }
    // END: ThemeEditor - Public Functions

    Product.name = "Product";
    return Product;
}();

// ---------------------------------------------------------------------------------
// Bizweb Js - Money Format
//
// Working with Money format.
// ---------------------------------------------------------------------------------
Bizweb.money_format = "{{amount}} VND";
Bizweb.formatMoney = function (cents, format) {
    if (typeof cents == 'string') {
        cents = cents.replace(/\./g, '');
        cents = cents.replace(/\,/g, '');
    }

    var value = '';
    var placeholderRegex = /\{\{\s*(\w+)\s*\}\}/;
    var formatString = (format || this.money_format);

    function formatWithDelimiters(number, precision, thousands, decimal) {
        if (typeof precision == 'undefined')
            precision = 2;
        if (typeof thousands == 'undefined')
            thousands = '.';
        if (typeof decimal == 'undefined')
            decimal = ',';

        if (typeof number == "undefined" || number == null) {
            return 0;
        }

        number = number.toFixed(precision);
        var parts = number.split('.');
        var dollars = parts[0].replace(/(\d)(?=(\d\d\d)+(?!\d))/g, '$1' + thousands);
        var cents = parts[1] ? (decimal + parts[1]) : '';

        return dollars + cents;
    }

    switch (formatString.match(placeholderRegex)[1]) {
        case 'amount':
            value = formatWithDelimiters(cents, 2);
            break;
        case 'amount_no_decimals':
            value = formatWithDelimiters(cents, 0);
            break;
        case 'amount_with_comma_separator':
            value = formatWithDelimiters(cents, 2, '.', ',');
            break;
        case 'amount_no_decimals_with_comma_separator':
            value = formatWithDelimiters(cents, 0, '.', ',');
            break;
    }

    return formatString.replace(placeholderRegex, value);
}

// ---------------------------------------------------------------------------------
// Bizweb Js - OptionSelectors
//
// Working with Option Selectors.
// ---------------------------------------------------------------------------------
Bizweb.OptionSelectors = function () {
    function OptionSelectors(existingSelectorId, options) {
        this.selectorDivClass = 'selector-wrapper';
        this.selectorClass = 'single-option-selector';
        this.variantIdFieldIdSuffix = '-variant-id';

        this.variantIdField = null;
        this.selectors = [];
        this.domIdPrefix = existingSelectorId;
        this.product = new Bizweb.Product(options.product);

        if (typeof options.onVariantSelected != "undefined")
            this.onVariantSelected = options.onVariantSelected;
        else
            this.onVariantSelected = function () { };

        this.replaceSelector(existingSelectorId);
        this.initDropdown();

        return true;
    };

    // BEGIN: ThemeEditor - Public Functions
    OptionSelectors.prototype.replaceSelector = function (domId) {
        var oldSelector = document.getElementById(domId);
        var parent = oldSelector.parentNode;

        Bizweb.each(this.buildSelectors(), function (el) {
            parent.insertBefore(el, oldSelector);
        });

        oldSelector.style.display = 'none';
        this.variantIdField = oldSelector;
    };
    OptionSelectors.prototype.buildSelectors = function () {
        // build selectors
        for (var i = 0; i < this.product.optionNames().length; i++) {
            var sel = new Bizweb.SingleOptionSelector(this, i, this.product.optionNames()[i], this.product.optionValues(i));
            sel.element.disabled = false;
            this.selectors.push(sel);
        }

        // replace existing selector with new selectors, new hidden input field, new hidden messageElement
        var divClass = this.selectorDivClass;
        var optionNames = this.product.optionNames();
        var elements = Bizweb.map(this.selectors, function (selector) {
            var div = document.createElement('div');
            div.setAttribute('class', divClass);
            // create label if more than 1 option (ie: more than one drop down)
            if (optionNames.length > 1) {
                // create and appened a label into div
                var label = document.createElement('label');
                label.htmlFor = selector.element.id;
                label.innerHTML = selector.name;
                div.appendChild(label);
            }
            div.appendChild(selector.element);
            return div;
        });

        return elements;
    };
    OptionSelectors.prototype.initDropdown = function () {
        var options = { initialLoad: true };
        var successDropdownSelection = this.selectVariantFromDropdown(options);
        if (!successDropdownSelection) {
            var optionSelectors = this;

            setTimeout(function () {
                if (!optionSelectors.selectVariantFromParams(options))
                    optionSelectors.selectors[0].element.onchange(options);
            });
        }
    };
    OptionSelectors.prototype.selectVariantFromDropdown = function (options) {
        var variantSelected = document.getElementById(this.domIdPrefix).querySelector("[selected]");
        if (!variantSelected)
            return false;

        return this.selectVariant(variantSelected.value, options);
    };
    OptionSelectors.prototype.selectVariantFromParams = function (options) {
        var variantId = Bizweb.getUrlParameter("variantid");
        if (variantId == null)
            variantId = Bizweb.getUrlParameter("variantId");

        return this.selectVariant(variantId, options);
    };
    OptionSelectors.prototype.selectVariant = function (variantId, options) {
        var variant = this.product.getVariantById(variantId);
        if (variant == null)
            return false;

        for (var i = 0; i < this.selectors.length; i++) {
            var element = this.selectors[i].element;
            var optionName = element.getAttribute("data-option")

            var value = variant[optionName];
            if (value == null || !this.optionExistInSelect(element, value))
                continue;

            element.value = value;
        }

        if (typeof jQuery !== 'undefined')
            jQuery(this.selectors[0].element).trigger('change', options);
        else
            this.selectors[0].element.onchange(options);

        return true;
    };
    OptionSelectors.prototype.optionExistInSelect = function (select, value) {
        for (var i = 0; i < select.options.length; i++) {
            if (select.options[i].value == value)
                return true;
        }
    };
    OptionSelectors.prototype.updateSelectors = function (index, options) {
        var currValues = this.selectedValues(); // get current values
        var variant = this.product.getVariant(currValues);
        if (variant) {
            this.variantIdField.disabled = false;
            this.variantIdField.value = variant.id; // update hidden selector with new variant id
        } else {
            this.variantIdField.disabled = true;
        }

        this.onVariantSelected(variant, this, options);  // callback

        if (this.historyState != null) {
            this.historyState.onVariantChange(variant, this, options);
        }
    };
    OptionSelectors.prototype.selectedValues = function () {
        var currValues = [];
        for (var i = 0; i < this.selectors.length; i++) {
            var thisValue = this.selectors[i].element.value;
            currValues.push(thisValue);
        }
        return currValues;
    };
    // END: ThemeEditor - Public Functions

    OptionSelectors.name = "OptionSelectors";
    return OptionSelectors;
}();

// ---------------------------------------------------------------------------------
// Bizweb Js - SingleOptionSelector
//
// Working with Option Selectors.
// ---------------------------------------------------------------------------------
Bizweb.SingleOptionSelector = function (multiSelector, index, name, values) {
    this.multiSelector = multiSelector;
    this.values = values;
    this.index = index;
    this.name = name;
    this.element = document.createElement('select');
    for (var i = 0; i < values.length; i++) {
        var opt = document.createElement('option');
        opt.value = values[i];
        opt.innerHTML = values[i];
        this.element.appendChild(opt);
    }
    this.element.setAttribute('class', this.multiSelector.selectorClass);
    this.element.setAttribute('data-option', 'option' + (index + 1));
    this.element.id = multiSelector.domIdPrefix + '-option-' + index;
    this.element.onchange = function (event, options) {
        options = options || {};

        multiSelector.updateSelectors(index, options);
    };

    return true;
};

// ---------------------------------------------------------------------------------
// Bizweb Js - SingleOptionSelector
//
// Working with Option Selectors.
// ---------------------------------------------------------------------------------
Bizweb.Image = {
    preload: function (t, e) {
        for (var o = 0; o < t.length; o++) {
            var i = t[o];
            this.loadImage(this.getSizedImageUrl(i, e))
        }
    },
    loadImage: function (src) {
        (new Image).src = src
    },
    switchImage: function (image, element, callback) {
        if (!image || !element) {
            return;
        }

        var size = this.imageSize(element.src)
        var imageUrl = this.getSizedImageUrl(image.src, size);

        if (callback) {
            callback(imageUrl, image, element);
        } else {
            element.src = imageUrl;
        }
    },
    imageSize: function (src) {
        var match = src.match(/thumb\/(1024x1024|2048x2048|pico|icon|thumb|small|compact|medium|large|grande)\//);
        if (match != null)
            return match[1];
        else
            return null;
    },
    getSizedImageUrl: function (src, size) {
        if (size == null)
            return src;

        if (size == 'master')
            return this.removeProtocol(src);

        var match = src.match(/\.(jpg|jpeg|gif|png|bmp|bitmap|tiff|tif)(\?v=\d+)?$/i);
        if (match != null) {
            var thumbDomain = Bizweb.mediaDomainName + "thumb/" + size + "/";
            return this.removeProtocol(src).replace(Bizweb.mediaDomainName, thumbDomain).split('?')[0];
        } else {
            return null;
        }
    },
    removeProtocol: function (path) {
        return path.replace(/http(s)?:/, "");
    }
};