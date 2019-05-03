<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Crypt;

use UnitTester;

class SetKeyCest
{
    /**
     * Tests Phalcon\Crypt :: setKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function cryptSetKey(UnitTester $I)
    {
        $I->wantToTest('Crypt - setKey()');

        $I->skipTest('Need implementation');
    }
}
